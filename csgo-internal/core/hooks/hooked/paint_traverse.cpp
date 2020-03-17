#include "../hooks.hpp"

namespace cheat::core::hooks::paint_traverse {
	fn original = nullptr;

	void __fastcall hook(REGISTERS, const std::int32_t panel_name, const bool paint, const bool force) {
		original(ecx, panel_name, paint, force);

		static auto copy = 0;

		if (!copy && !std::strcmp(ifaces::get_ifaces.panel->get_panel_name(panel_name), "FocusOverlayPanel"))
			copy = panel_name;

		if (panel_name != copy)
			return;

		features::watermark();

		if (ifaces::get_ifaces.engine->is_connected() && ifaces::get_ifaces.engine->is_in_game())
			features::player();
	}
}
