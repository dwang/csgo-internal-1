#include "../hooks.hpp"

namespace cheat::core::hooks::scene_end {
	fn original = nullptr;

	void __fastcall hook(REGISTERS) {
		original(ecx);
	}
}
