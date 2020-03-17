#include "../hooks.hpp"

namespace cheat::core::hooks::reset {
	fn original = nullptr;

	long __fastcall hook(REGISTERS, IDirect3DDevice9* device, D3DPRESENT_PARAMETERS* presentation_parameters) {
		ImGui_ImplDX9_InvalidateDeviceObjects();

		auto hr = original(ecx, device, presentation_parameters);

		if (hr >= 0)
			ImGui_ImplDX9_CreateDeviceObjects();

		return hr;
	}
}
