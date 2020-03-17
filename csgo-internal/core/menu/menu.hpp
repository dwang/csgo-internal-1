#pragma once

#include <map>
#include <string>
#include <memory>

#include "vars.hpp"

#include "../features/features.hpp"
#include "../sdk/misc/render.hpp"

namespace cheat::core::menu {
	inline bool visible;
	inline ImGuiStyle style;

	inline std::size_t active_tab;
	inline std::map<std::string, void(*)()> render_tab;

	extern void menu_setup();
	extern void render();
}
