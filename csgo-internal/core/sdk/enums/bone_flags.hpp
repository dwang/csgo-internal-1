#pragma once

namespace cheat::sdk::enums {
	enum struct bone_flags {
		bone_calculate_mask = 0x1f,
		bone_physically_simulated = 0x01,
		bone_physics_procedural = 0x02,
		bone_always_procedural = 0x04,
		bone_screen_align_sphere = 0x08,
		bone_screen_align_cylinder = 0x10,
		bone_used_mask = 0x0007ff00,
		bone_used_by_anything = 0x0007ff00,
		bone_used_by_hitbox = 0x00000100,
		bone_used_by_attachment = 0x00000200,
		bone_used_by_vertex_mask = 0x0003fc00,
		bone_used_by_vertex_lod0 = 0x00000400,
		bone_used_by_vertex_lod1 = 0x00000800,
		bone_used_by_vertex_lod2 = 0x00001000,
		bone_used_by_vertex_lod3 = 0x00002000,
		bone_used_by_vertex_lod4 = 0x00004000,
		bone_used_by_vertex_lod5 = 0x00008000,
		bone_used_by_vertex_lod6 = 0x00010000,
		bone_used_by_vertex_lod7 = 0x00020000,
		bone_used_by_bone_merge = 0x00040000,
		bone_type_mask = 0x00f00000,
		bone_fixed_alignment = 0x00100000,
		bone_has_saveframe_pos = 0x00200000,
		bone_has_saveframe_rot = 0x00400000
	};
}
