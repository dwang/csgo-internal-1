#define WIN32_LEAN_AND_MEAN

#include <filesystem>
#include <string>
#include <thread>
#include <Windows.h>
#include <TlHelp32.h>

#define DLL_NAME "csgo-internal.dll"
#define PROCESS_NAME L"csgo.exe"

auto get_process_info(const wchar_t* name) -> std::uint32_t {
	auto snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (snapshot == INVALID_HANDLE_VALUE)
		return false;

	auto entry = PROCESSENTRY32{ sizeof(PROCESSENTRY32) };

	if (Process32First(snapshot, &entry)) {
		do {
			if (!wcscmp(entry.szExeFile, name)) {
				CloseHandle(snapshot);
				return entry.th32ProcessID;
			}
		} while (Process32Next(snapshot, &entry));
	}

	CloseHandle(snapshot);

	return 0;
}

auto main() -> BOOL {
	auto file_path = std::filesystem::canonical(DLL_NAME).wstring();

	auto process_id = get_process_info(PROCESS_NAME);

	auto process_handle = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_CREATE_THREAD, FALSE, process_id);
	auto path_alloc = VirtualAllocEx(process_handle, NULL, file_path.size() * 2, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	WriteProcessMemory(process_handle, path_alloc, file_path.c_str(), file_path.size() * 2, nullptr);

	auto remote_thread = CreateRemoteThread(process_handle, NULL, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(LoadLibraryW), path_alloc, NULL, NULL);
	WaitForSingleObject(remote_thread, INFINITE);

	if (path_alloc)
		VirtualFreeEx(process_handle, path_alloc, 0, MEM_RELEASE);

	if (remote_thread)
		CloseHandle(remote_thread);

	if (process_handle)
		CloseHandle(process_handle);

	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	return EXIT_SUCCESS;
}
