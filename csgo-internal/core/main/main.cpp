#include "main.hpp"

namespace cheat::core::main {
	BOOL WINAPI detach() {
		hooks::hooks_destroy();

		return TRUE;
	}

	DWORD WINAPI attach(const LPVOID thread) {
		ifaces::ifaces{ };
		mem::mem{ };

		sdk::misc::get_netvar_tree = std::make_unique<sdk::misc::netvar_tree>();
		sdk::misc::render_setup();
		sdk::misc::input_helper_setup();

		menu::menu_setup();

		hooks::hooks_create();

		while (!menu::checkbox["#unload_cheat_checkbox"]->get_bool())
			std::this_thread::sleep_for(std::chrono::milliseconds(50));

		std::this_thread::sleep_for(std::chrono::milliseconds(400));

		detach();

		FreeLibraryAndExitThread(static_cast<HMODULE>(thread), EXIT_SUCCESS);
	}
}
