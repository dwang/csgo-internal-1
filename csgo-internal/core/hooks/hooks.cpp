#include "hooks.hpp"

#include <thread>

namespace cheat::core::hooks {
	void hooks_create() {
		if (MH_Initialize() != MH_OK) {
			throw std::runtime_error("failed to initialize MH_Initialize.");
		}

		SETUP_HOOK(HOOK_TARGET(mem::get_mem.client_mode, 24), create_move::hook, create_move::original);
		SETUP_HOOK(HOOK_TARGET(ifaces::get_ifaces.direct3d_device, 42), end_scene::hook, end_scene::original);
		SETUP_HOOK(HOOK_TARGET(ifaces::get_ifaces.direct3d_device, 16), reset::hook, reset::original);
		SETUP_HOOK(HOOK_TARGET(ifaces::get_ifaces.sound, 5), emit_sound::hook, emit_sound::original);
		SETUP_HOOK(HOOK_TARGET(ifaces::get_ifaces.base_client, 37), frame_stage_notify::hook, frame_stage_notify::original);
		SETUP_HOOK(HOOK_TARGET(ifaces::get_ifaces.base_client, 21), in_key_event::hook, in_key_event::original);
		SETUP_HOOK(HOOK_TARGET(ifaces::get_ifaces.surface, 67), lock_cursor::hook, lock_cursor::original);
		SETUP_HOOK(HOOK_TARGET(mem::get_mem.client_mode, 18), override_view::hook, override_view::original);
		SETUP_HOOK(HOOK_TARGET(ifaces::get_ifaces.panel, 41), paint_traverse::hook, paint_traverse::original);
		SETUP_HOOK(HOOK_TARGET(ifaces::get_ifaces.render_view, 9), scene_end::hook, scene_end::original);

		if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) {
			throw std::runtime_error("failed to enable hooks.");
		}

		wndproc::original = reinterpret_cast<WNDPROC>(SetWindowLongPtrA(FindWindowA("Valve001", nullptr), GWL_WNDPROC, reinterpret_cast<LONG_PTR>(wndproc::hook)));
	}

	void hooks_destroy() {
		MH_Uninitialize();

		SetWindowLongPtrA(FindWindowA("Valve001", nullptr), GWL_WNDPROC, reinterpret_cast<LONG_PTR>(wndproc::original));
	}
}
