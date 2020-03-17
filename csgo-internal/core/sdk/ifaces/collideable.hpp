#pragma once

#include "../misc/vector.hpp"
#include "../misc/vfunc_from_index.hpp"

namespace cheat::sdk::ifaces {
	struct collideable_t {
		misc::vector& mins() {
			return misc::vfunc_from_index<misc::vector&(__thiscall*)(void*)>(this, 1)(this);
		}

		misc::vector& maxs() {
			return misc::vfunc_from_index<misc::vector&(__thiscall*)(void*)>(this, 2)(this);
		}
	};
}
