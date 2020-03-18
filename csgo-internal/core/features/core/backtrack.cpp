#include "misc.hpp"

#include "../../sdk/misc/vector.hpp"
#include "../../sdk/misc/macros.hpp"

#define _USE_MATH_DEFINES
#include <math.h>

cheat::sdk::misc::vector angle_vector(cheat::sdk::misc::vector to_convert)
{
	auto y_sin = sin(to_convert.y / 180.f * static_cast<float>(M_PI));
	auto y_cos = cos(to_convert.y / 180.f * static_cast<float>(M_PI));

	auto x_sin = sin(to_convert.x / 180.f * static_cast<float>(M_PI));
	auto x_cos = cos(to_convert.x / 180.f * static_cast<float>(M_PI));

	return cheat::sdk::misc::vector(x_cos * y_cos, x_cos * y_sin, -x_sin);
}

float distance_point_to_line(cheat::sdk::misc::vector point, cheat::sdk::misc::vector origin, cheat::sdk::misc::vector direction)
{
	auto delta = point - origin;

	auto offset = delta.dot(direction) / (direction.x * direction.x + direction.y * direction.y + direction.z * direction.z);
	if (offset < 0.000001f)
		return FLT_MAX;

	auto perpendicular_point = origin + (direction * offset);
	return (point - perpendicular_point).length();
}

struct backtrack_tick {
	float simulation_time;
	cheat::sdk::misc::vector hitbox_position;
	cheat::sdk::misc::vector origin;
};

namespace cheat::core::features {
	backtrack_tick data[64][12];

	void backtrack(sdk::ifaces::user_cmd* cmd) {
		int best_target = -1;
		float best_fov = 90.0f;

		static auto local_player = ifaces::get_ifaces.client_entity->get_client_entity(ifaces::get_ifaces.engine->get_local_player());

		if (!local_player)
			return;

		if (local_player->get_health() <= 0)
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

			data[index][cmd->command_number % vars::aim::backtrack_ticks + 1] = backtrack_tick{ entity->get_simulation_time(), entity->get_bone_position(8), sdk::misc::vector{} };
			sdk::misc::vector view_direction = angle_vector(cmd->view_angles);
			float fov = distance_point_to_line(entity->get_bone_position(8), local_player->get_bone_position(8), view_direction);

			if (best_fov > fov) {
				best_fov = fov;
				best_target = index;
			}
		}

		float best_target_simulation_time = 0.f;

		if (best_target != -1) {
			float temp = FLT_MAX;
			sdk::misc::vector view_direction = angle_vector(cmd->view_angles);

			for (int t = 0; t < vars::aim::backtrack_ticks; ++t) {
				float fov = distance_point_to_line(data[best_target][t].hitbox_position, local_player->get_bone_position(8), view_direction);
				if (temp > fov && data[best_target][t].simulation_time > local_player->get_simulation_time() - 1) {
					temp = fov;
					best_target_simulation_time = data[best_target][t].simulation_time;
				}
			}

			if (cmd->buttons & CONV_ENUM_TYPE(std::int32_t, sdk::enums::button::button_attack))
				cmd->tick_count = static_cast<int>(0.5f + best_target_simulation_time / mem::get_mem.global_vars->interval_per_tick);
		}
	}
}
