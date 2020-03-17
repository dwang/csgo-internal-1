#pragma once

namespace cheat::core::vars {
	namespace aim {
		inline bool backtrack = true;
		inline int backtrack_ticks = 12;
	}

	namespace visuals {
		inline int esp_mode = 2;
		inline bool box_esp = true;
		inline bool name_esp = true;
		inline bool health_esp = true;
		inline bool armor_esp = true;
		inline bool scoped_esp = true;
		inline bool chams = true;
		inline bool chams_ignore_z = false;
		inline bool flash_alpha = false;
		inline float flash_alpha_value = 255.0f;
		inline bool view_model_fov = false;
		inline float view_model_fov_value = 0.0f;
	}

	namespace misc {
		inline bool watermark = true;
		inline bool bunnyhop = false;
		inline bool grenade_preview = true;
		inline bool rank_reveal = true;
		inline bool unload = false;
	}
}
