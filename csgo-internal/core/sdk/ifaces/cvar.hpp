#pragma once

#include "convar.hpp"

#include "../misc/macros.hpp"

namespace cheat::sdk::ifaces {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/icvar.h

	struct cvar {
		VFUNC(find_cvar(const char* cvar), 15, convar* (__thiscall*)(void*, const char*), cvar);
	};
}
