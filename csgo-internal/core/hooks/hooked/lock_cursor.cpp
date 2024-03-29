#include "../hooks.hpp"

namespace cheat::core::hooks::lock_cursor {
	fn original = nullptr;

	void __fastcall hook(REGISTERS) {
		if (menu::visible) {
			ifaces::get_ifaces.surface->unlock_cursor();
			return;
		}
		else {
			ifaces::get_ifaces.input_system->enable_input(true);
		}

		original(ecx);
	}
}
