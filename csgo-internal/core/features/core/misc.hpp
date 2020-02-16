#pragma once

#include <cmath>

#include "../../ifaces/ifaces.hpp"
#include "../../menu/menu.hpp"
#include "../../sdk/sdk.hpp"
#include "../../../dependencies/fgui/FGUI.hh"

namespace cheat::core::features {
	extern void bunny_hop(sdk::ifaces::user_cmd*);
	extern void rank_revealer();
	extern void disconnect_to_lobby();
}
