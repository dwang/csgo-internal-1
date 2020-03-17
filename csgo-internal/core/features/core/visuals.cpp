#include "misc.hpp"

namespace cheat::core::features {
	bool get_bounding_box(sdk::ifaces::entity* entity, sdk::misc::box& in) {
		sdk::misc::vector origin = entity->get_vec_origin();
		sdk::misc::vector min = entity->collideable()->mins() + origin;
		sdk::misc::vector max = entity->collideable()->maxs() + origin;

		sdk::misc::vector points[] =
		{
			sdk::misc::vector(min.x, min.y, min.z),
			sdk::misc::vector(min.x, max.y, min.z),
			sdk::misc::vector(max.x, max.y, min.z),
			sdk::misc::vector(max.x, min.y, min.z),
			sdk::misc::vector(max.x, max.y, max.z),
			sdk::misc::vector(min.x, min.y, max.z),
			sdk::misc::vector(min.x, max.y, max.z),
			sdk::misc::vector(max.x, min.y, max.z)
		};

		sdk::misc::vector flb, brt, blb, frt, frb, brb, blt, flt;

		if (ifaces::get_ifaces.debug_overlay->screen_position(points[3], flb) == 1 || ifaces::get_ifaces.debug_overlay->screen_position(points[5], brt) == 1 ||
			ifaces::get_ifaces.debug_overlay->screen_position(points[0], blb) == 1 || ifaces::get_ifaces.debug_overlay->screen_position(points[4], frt) == 1 ||
			ifaces::get_ifaces.debug_overlay->screen_position(points[2], frb) == 1 || ifaces::get_ifaces.debug_overlay->screen_position(points[1], brb) == 1 ||
			ifaces::get_ifaces.debug_overlay->screen_position(points[6], blt) == 1 || ifaces::get_ifaces.debug_overlay->screen_position(points[7], flt) == 1)
			return false;

		sdk::misc::vector arr[] = { flb, brt, blb, frt, frb, brb, blt, flt };
		
		float left, top, right, bottom;

		left = flb.x;
		top = flb.y;
		right = flb.x;
		bottom = flb.y;

		for (int i = 1; i < 8; i++)
		{
			if (left > arr[i].x)
				left = arr[i].x;
			if (bottom < arr[i].y)
				bottom = arr[i].y;
			if (right < arr[i].x)
				right = arr[i].x;
			if (top > arr[i].y)
				top = arr[i].y;
		}

		in.x = static_cast<int>(left);
		in.y = static_cast<int>(top);
		in.w = static_cast<int>(right - left);
		in.h = static_cast<int>(bottom - top);

		return true;
	}

	void watermark() {
		if (vars::misc::watermark)
			sdk::misc::text(5, 5, cheat::sdk::misc::color(255, 255, 255), sdk::misc::fonts[CONV_ENUM_TYPE(std::int32_t, sdk::enums::font::font_watermark)], "csgo-internal");
	}

	void player() {
		static auto local_player = ifaces::get_ifaces.client_entity->get_client_entity(ifaces::get_ifaces.engine->get_local_player());

		if (!local_player)
			return;

		if (vars::visuals::esp_mode == 0)
			return;

		if (vars::visuals::esp_mode == 2 && local_player->get_health() > 0)
			return;

		for (auto index = 1; index <= mem::get_mem.global_vars->max_clients; index++) {
			const auto entity = ifaces::get_ifaces.client_entity->get_client_entity(index);

			if (!entity)
				continue;

			if (!(entity->get_health() > 0))
				continue;

			if (entity == local_player)
				continue;

			if (!(local_player->get_team() != entity->get_team()))
				continue;

			if (entity->is_dormant())
				continue;

			static sdk::ifaces::player_info player_info;

			if (!ifaces::get_ifaces.engine->get_player_info(index, player_info))
				continue;

			static sdk::misc::vector screen;

			if (!(ifaces::get_ifaces.debug_overlay->screen_position(entity->get_vec_origin(), screen) != 1))
				continue;

			static sdk::misc::box bounding_box;

			if (!get_bounding_box(entity, bounding_box))
				continue;

			if (vars::visuals::box_esp)
				sdk::misc::outlined_rectangle(bounding_box.x, bounding_box.y, bounding_box.w, bounding_box.h, sdk::misc::color(255, 255, 255));

			if (vars::visuals::name_esp) {
				auto player_name = player_info.fake_player ? fmt::format("BOT - {}", player_info.name) : player_info.name;

				if (player_name.length() > 18)
					player_name = player_name.substr(0, 18) + "...";

				sdk::misc::text(bounding_box.x + (bounding_box.w / 2), bounding_box.y - 23, cheat::sdk::misc::color(255, 150, 0), sdk::misc::fonts[CONV_ENUM_TYPE(std::int32_t, sdk::enums::font::font_visuals)], player_name, true);
			}

			if (vars::visuals::health_esp)
				sdk::misc::text(static_cast<int>(screen.x), static_cast<int>(screen.y) + 15, cheat::sdk::misc::color(255, 255, 255), sdk::misc::fonts[CONV_ENUM_TYPE(std::int32_t, sdk::enums::font::font_visuals)], fmt::format("H: {:d}", entity->get_health()), true);

			if (vars::visuals::armor_esp)
				sdk::misc::text(static_cast<int>(screen.x), static_cast<int>(screen.y) + 30, cheat::sdk::misc::color(255, 255, 255), sdk::misc::fonts[CONV_ENUM_TYPE(std::int32_t, sdk::enums::font::font_visuals)], fmt::format("A: {:d}", entity->get_armor_value()), true);

			if (vars::visuals::scoped_esp)
				sdk::misc::text(static_cast<int>(screen.x), static_cast<int>(screen.y) + 45, cheat::sdk::misc::color(0, 128, 255), sdk::misc::fonts[CONV_ENUM_TYPE(std::int32_t, sdk::enums::font::font_visuals)], entity->is_scoped() ? "Scoped" : "Not Scoped", true);
		}
	}

	void grenade_preview() {
		static auto cvar = ifaces::get_ifaces.cvar->find_cvar("cl_grenadepreview");
		static auto local_player = ifaces::get_ifaces.client_entity->get_client_entity(ifaces::get_ifaces.engine->get_local_player());

		if (!cvar || !local_player)
			return;

		if (!(local_player->get_health() > 0))
			return;

		cvar->set_value(vars::misc::grenade_preview ? 1 : 0);
	}

	void flash_alpha() {
		static auto local_player = ifaces::get_ifaces.client_entity->get_client_entity(ifaces::get_ifaces.engine->get_local_player());

		if (!local_player)
			return;

		local_player->get_flash_alpha() = vars::visuals::flash_alpha ? vars::visuals::flash_alpha_value : 255.0f;
	}

	void view_model_fov(sdk::ifaces::view_setup* view_setup) {
		static auto local_player = ifaces::get_ifaces.client_entity->get_client_entity(ifaces::get_ifaces.engine->get_local_player());

		if (!local_player)
			return;

		view_setup->view_model_fov += vars::visuals::view_model_fov && !local_player->is_scoped() ? vars::visuals::view_model_fov_value : 0.0f;
	}
}
