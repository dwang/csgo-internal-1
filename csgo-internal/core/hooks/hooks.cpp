#include "hooks.hpp"

namespace cheat::core::hooks {
	void hooks_create() {
		if (MH_Initialize() != MH_OK) {
			throw std::runtime_error("failed to initialize MH_Initialize.");
		}

		SETUP_HOOK(HOOK_TARGET(mem::get_mem.client_mode, 24), create_move::hook, create_move::original);
		SETUP_HOOK(HOOK_TARGET(ifaces::get_ifaces.sound, 5), emit_sound::hook, emit_sound::original);
		SETUP_HOOK(HOOK_TARGET(ifaces::get_ifaces.base_client, 37), frame_stage_notify::hook, frame_stage_notify::original);
		SETUP_HOOK(HOOK_TARGET(mem::get_mem.client_mode, 18), override_view::hook, override_view::original);
		SETUP_HOOK(HOOK_TARGET(ifaces::get_ifaces.panel, 41), paint_traverse::hook, paint_traverse::original);
		SETUP_HOOK(HOOK_TARGET(ifaces::get_ifaces.render_view, 9), scene_end::hook, scene_end::original);

		if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) {
			throw std::runtime_error("failed to enable hooks.");
		}
	}

	void hooks_destroy() {
		MH_Uninitialize();
	}
}
