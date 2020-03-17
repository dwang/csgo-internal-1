#pragma once

#include <vector>

#include "../../ifaces/ifaces.hpp"

#include <d3d9.h>
#include <d3dx9.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include "../../../dependencies/imgui/imgui.h"
#include "../../../dependencies/imgui/imgui_internal.h"
#include "../../../dependencies/imgui/imgui_impl_dx9.h"
#include "../../../dependencies/imgui/imgui_impl_win32.h"

namespace cheat::sdk::misc {
	inline std::vector<std::int32_t> fonts;

	extern void create_font(std::int32_t&, std::string_view, std::int32_t, std::int32_t, bool);
	extern void get_screen_size(std::int32_t&, std::int32_t&);
	extern void get_text_size(const std::int32_t&, std::string_view, int, int);
	extern void rectangle(std::int32_t, std::int32_t, std::int32_t, std::int32_t, color);
	extern void outlined_rectangle(std::int32_t, std::int32_t, std::int32_t, std::int32_t, color);
	extern void line(std::int32_t, std::int32_t, std::int32_t, std::int32_t, color);
	extern void text(std::int32_t, std::int32_t, color, unsigned long, std::string_view, bool = false);
	extern void circle(std::int32_t, std::int32_t, std::int32_t, std::int32_t, color);
	extern void gradient(std::int32_t, std::int32_t, std::int32_t, std::int32_t, std::int32_t, std::int32_t, color, bool);
	extern void colored_gradient(std::int32_t, std::int32_t, std::int32_t, std::int32_t, color, color, bool);
	extern void get_alpha_value(std::int32_t, std::int32_t, std::int32_t, std::int32_t);

	extern void font_setup();
	extern void render_setup(IDirect3DDevice9* device, HWND window);
}
