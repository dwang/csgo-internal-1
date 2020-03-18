#include "chams.hpp"
#include "../../hooks/hooks.hpp"

namespace cheat::core::features {
	void draw_model_execute(REGISTERS, sdk::ifaces::material_render_context* ctx, void* state, sdk::ifaces::model_render_info& info, sdk::misc::matrix3x4* custom_bone_to_world) {
		if (!vars::visuals::chams)
			return;

		static auto local_player = ifaces::get_ifaces.client_entity->get_client_entity(ifaces::get_ifaces.engine->get_local_player());

		if (!local_player)
			return;

		auto entity = ifaces::get_ifaces.client_entity->get_client_entity(info.entity_index);

		if (!entity)
			return;

		if (!(entity->get_health() > 0))
			return;

		if (entity == local_player)
			return;

		if (!(local_player->get_team() != entity->get_team()))
			return;

		if (entity->is_dormant())
			return;

		static auto material = ifaces::get_ifaces.material_system->find_material("debug/debugambientcube");

		if (vars::visuals::chams_ignore_z) {
			material->set_flag(static_cast<std::uint32_t>(sdk::enums::material::material_ignorez), true);

			if (local_player->get_team() == entity->get_team())
				material->set_color(1.0f, 1.0f, 1.0f);
			else
				material->set_color(255.0f / 255.0f, 105.0f / 255.0f, 180.0f / 255.0f);
			
			ifaces::get_ifaces.model_render->override_material(material);
			hooks::draw_model_execute::original(ecx, ctx, state, info, custom_bone_to_world);
		}

		if (local_player->get_team() == entity->get_team())
			material->set_color(30.0f / 255.0f, 144.0f / 255.0f, 255.0f / 255.0f);
		else
			material->set_color(150.0f / 255.0f, 200.0f / 255.0f, 60.0f / 255.0f);

		material->set_flag(static_cast<std::uint32_t>(sdk::enums::material::material_ignorez), false);
		ifaces::get_ifaces.model_render->override_material(material);
	}
}