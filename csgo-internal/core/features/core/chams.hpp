#pragma once

#include "../../ifaces/ifaces.hpp"
#include "../../menu/menu.hpp"
#include "../../sdk/sdk.hpp"

namespace cheat::core::features {
	extern void draw_model_execute(REGISTERS, sdk::ifaces::material_render_context* ctx, void* state, sdk::ifaces::model_render_info& info, sdk::misc::matrix3x4* custom_bone_to_world);
}