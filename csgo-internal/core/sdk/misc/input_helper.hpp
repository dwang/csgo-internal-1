#pragma once

#include "../../ifaces/ifaces.hpp"
#include "../../../dependencies/fgui/FGUI.hh"

namespace cheat::sdk::misc {
	extern fgui::state get_key_state(const fgui::key&);
	extern fgui::delta get_scroll_delta();
	extern fgui::point get_mouse_position();

	extern void input_helper_setup();
}