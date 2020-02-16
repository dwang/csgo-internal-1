#include "../hooks.hpp"

namespace cheat::core::hooks::in_key_event {
	fn original = nullptr;

	int __fastcall hook(REGISTERS, int event_code, int key_num, const char* current_binding) {
		if (menu::container["#window"]->get_state())
			return 0;

		return original(ecx, event_code, key_num, current_binding);
	}
}
