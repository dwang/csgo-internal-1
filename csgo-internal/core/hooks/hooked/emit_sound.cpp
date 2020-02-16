#include "../hooks.hpp"

namespace cheat::core::hooks::emit_sound {
	fn original = nullptr;

	void __fastcall hook(REGISTERS, const sdk::ifaces::sound_data sound_data) {
		original(ecx, sound_data);
	}
}
