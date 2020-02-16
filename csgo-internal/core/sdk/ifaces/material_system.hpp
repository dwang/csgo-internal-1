#pragma once

#include "material.hpp"

#include "../misc/macros.hpp"

namespace cheat::sdk::ifaces {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/public/materialsystem/imaterialsystem.h

	struct material_system {
		VFUNC(find_material(const char* material_name), 84, material* (__thiscall*)(void*, const char*, const char*, bool, const char*), material_name, nullptr, true, nullptr);
	};
}
