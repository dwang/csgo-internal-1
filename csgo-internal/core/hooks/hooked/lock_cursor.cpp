#include "../hooks.hpp"

namespace cheat::core::hooks::lock_cursor {
	fn original = nullptr;

	void __fastcall hook(REGISTERS) {
		if (menu::container["#window"]->get_state()) {
			ifaces::get_ifaces.surface->unlock_cursor();
			return;

			ifaces::get_ifaces.input_system->enable_input(false);
		}
		else {
			ifaces::get_ifaces.input_system->enable_input(true);
		}

		original(ecx);
	}
}
