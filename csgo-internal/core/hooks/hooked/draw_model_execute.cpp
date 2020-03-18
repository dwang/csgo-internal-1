#include "../hooks.hpp"

namespace cheat::core::hooks::draw_model_execute {
	fn original = nullptr;

	void __fastcall hook(REGISTERS, sdk::ifaces::material_render_context* ctx, void* state, sdk::ifaces::model_render_info& info, sdk::misc::matrix3x4* custom_bone_to_world) {
		features::draw_model_execute(ecx, edx, ctx, state, info, custom_bone_to_world);
		
		original(ecx, ctx, state, info, custom_bone_to_world);
		ifaces::get_ifaces.model_render->override_material(nullptr);
	}
}
