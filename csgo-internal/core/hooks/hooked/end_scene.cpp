#include "../hooks.hpp"

namespace cheat::core::hooks::end_scene {
	fn original = nullptr;

	long __fastcall hook(REGISTERS, IDirect3DDevice9* device) {
		static auto once = false;

		if (!once) {
			cheat::sdk::misc::render_setup(device, FindWindowA("Valve001", nullptr));
			once = true;
		}

		ImGui::GetIO().MouseDrawCursor = menu::visible;
		ImGui_ImplDX9_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		if (menu::visible)
			menu::render();

		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

		return original(ecx, device);
	}
}
