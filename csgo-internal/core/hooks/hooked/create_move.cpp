#include "../hooks.hpp"

namespace cheat::core::hooks::create_move {
	fn original = nullptr;

	bool __fastcall hook(REGISTERS, const float frame, sdk::ifaces::user_cmd* cmd) {
		if (!cmd || !cmd->command_number)
			original(ecx, frame, cmd);

		if (ifaces::get_ifaces.engine->is_connected() && ifaces::get_ifaces.engine->is_in_game() && cmd != nullptr) {
			features::backtrack(cmd);
			features::grenade_preview();
			features::flash_alpha();
			features::bunny_hop(cmd);
			features::rank_revealer();

			cmd->view_angles.clamp();
		}

		return false;
	}
}
