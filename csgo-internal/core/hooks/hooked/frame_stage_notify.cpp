#include "../hooks.hpp"

namespace cheat::core::hooks::frame_stage_notify {
	fn original = nullptr;

	void __fastcall hook(REGISTERS, const sdk::enums::client_frame_stage client_frame_stage) {
		original(ecx, client_frame_stage);
	}
}
