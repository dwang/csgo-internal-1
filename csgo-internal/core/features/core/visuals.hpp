#pragma once

#define FMT_HEADER_ONLY

#include "../../ifaces/ifaces.hpp"
#include "../../mem/mem.hpp"
#include "../../menu/menu.hpp"
#include "../../sdk/sdk.hpp"
#include "../../../dependencies/fmt/format.hpp"

namespace cheat::core::features {
	extern void watermark();
	extern void player();
	extern void grenade_preview();
	extern void flash_alpha();
	extern void view_model_fov(sdk::ifaces::view_setup*);
}
