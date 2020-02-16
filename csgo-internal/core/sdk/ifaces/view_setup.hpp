#pragma once

#include "../misc/macros.hpp"

namespace cheat::sdk::ifaces {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/public/view_shared.h

	struct view_setup {
		PAD(pad_1, 176);

		float view_model_fov;
	};
}
