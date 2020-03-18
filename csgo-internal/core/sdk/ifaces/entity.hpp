#pragma once

#include "collideable.hpp"

#include "../misc/vector.hpp"
#include "../misc/netvar_tree.hpp"
#include "../misc/matrix.hpp"

namespace cheat::sdk::ifaces {
	struct entity {
		OFFSET(is_dormant(), bool, 0xED);

		NETVAR(get_health(), std::int32_t, "DT_BasePlayer", "m_iHealth");
		NETVAR(get_armor_value(), std::int32_t, "DT_CSPlayer", "m_ArmorValue");
		NETVAR(get_flags(), std::int32_t, "DT_BasePlayer", "m_fFlags");
		NETVAR(get_team(), std::int32_t, "DT_BaseEntity", "m_iTeamNum");
		NETVAR(get_round_kills(), std::int32_t, "DT_CSPlayer", "m_iNumRoundKills");

		NETVAR(is_scoped(), bool, "DT_CSPlayer", "m_bIsScoped");
		NETVAR(is_controlling_bot(), bool, "DT_CSPlayer", "m_bIsControllingBot");
		NETVAR(has_helmet(), bool, "DT_CSPlayer", "m_bHasHelmet");
		NETVAR(has_defuse_kit(), bool, "DT_CSPlayer", "m_bHasDefuser");

		NETVAR(get_flash_duration(), float, "DT_CSPlayer", "m_bHasDefuser");
		NETVAR(get_flash_alpha(), float, "DT_CSPlayer", "m_flFlashMaxAlpha");
		NETVAR(get_health_shot_boost_expiration_time(), float, "DT_CSPlayer", "m_flHealthShotBoostExpirationTime");

		NETVAR(get_vec_origin(), misc::vector, "DT_BaseEntity", "m_vecOrigin");
		NETVAR(get_abs_origin(), misc::vector, "DT_BaseEntity", "m_angAbsOrigin");
		NETVAR(get_vec_view(), misc::vector, "DT_BasePlayer", "m_vecViewOffset[0]");

		NETVAR(get_simulation_time(), float, "DT_BaseEntity", "m_flSimulationTime");

		VFUNC(collideable(), 3, collideable_t*(__thiscall*)(void*));

		void* animating() {
			return reinterpret_cast<void*>(std::uintptr_t(this) + 0x4);
		}

		bool setup_bones(misc::matrix3x4* out, int max_bones, int mask, float time) {
			if (!this)
				return false;

			return misc::vfunc_from_index<bool(__thiscall*)(void*, misc::matrix3x4*, int, int, float)>(animating(), 13)(animating(), out, max_bones, mask, time);
		}

		misc::vector get_bone_position(int bone) {
			misc::matrix3x4 bone_matrix[128];

			if (setup_bones(bone_matrix, 128, CONV_ENUM_TYPE(std::int32_t, enums::bone_flags::bone_used_by_anything), 0.0f))
				return misc::vector(bone_matrix[bone][0][3], bone_matrix[bone][1][3], bone_matrix[bone][2][3]);

			return misc::vector{};
		}
	};
}
