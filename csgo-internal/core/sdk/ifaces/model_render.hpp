#pragma once

#include "material.hpp"

namespace cheat::sdk::ifaces {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/engine/ivmodelrender.h

	struct model_render {
		VFUNC(override_material(sdk::ifaces::material* material), 1, void(__thiscall*)(void*, sdk::ifaces::material*, int, int), material, 0, 0);
	};
}
