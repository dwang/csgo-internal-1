#pragma once

#include "../misc/macros.hpp"
#include "../misc/vector.hpp"
#include "../misc/matrix.hpp"

namespace cheat::sdk::ifaces {
	struct model_render_info {
		misc::vector origin;
		misc::vector angles;
		PAD(pad_1, 4);
		void* renderable;
		const void* model;
		const misc::matrix3x4* model_to_world;
		const misc::matrix3x4* lighting_offset;
		const misc::vector* lighting_origin;
		int flags;
		int entity_index;
		int skin;
		int body;
		int hitboxset;
		unsigned short instance;
	};
}
