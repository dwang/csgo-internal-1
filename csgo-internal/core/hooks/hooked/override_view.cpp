#include "../hooks.hpp"

namespace cheat::core::hooks::override_view {
	fn original = nullptr;

	void __fastcall hook(REGISTERS, sdk::ifaces::view_setup* view_setup) {
		if (ifaces::get_ifaces.engine->is_connected() && ifaces::get_ifaces.engine->is_in_game())
			features::view_model_fov(view_setup);

		original(ecx, view_setup);
	}
}
