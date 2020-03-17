#include "render.hpp"

namespace cheat::sdk::misc {
	void create_font(std::int32_t& font, const std::string_view family, const std::int32_t size, const std::int32_t flags, const bool bold) {
		font = core::ifaces::get_ifaces.surface->create_font();

		core::ifaces::get_ifaces.surface->set_font_glyph_set(font, family.data(), size, bold ? 800 : 0, 0, 0, flags, 0, 0);
	}

	void get_screen_size(std::int32_t& x, std::int32_t& y) {
		core::ifaces::get_ifaces.surface->get_screen_size(x, y);
	}

	void get_text_size(const std::int32_t& font, const std::string_view text, int w, int h) {
		core::ifaces::get_ifaces.surface->get_text_size(font, std::wstring(text.begin(), text.end()).data(), w, h);
	}

	void rectangle(const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h, const color color) {
		core::ifaces::get_ifaces.surface->draw_set_color(color.r, color.g, color.b, color.a);
		core::ifaces::get_ifaces.surface->draw_filled_rectangle(x, y, x + w, y + h);
	}

	void outlined_rectangle(const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h, const color color) {
		core::ifaces::get_ifaces.surface->draw_set_color(color.r, color.g, color.b, color.a);
		core::ifaces::get_ifaces.surface->draw_outlined_rectangle(x, y, x + w, y + h);
	}

	void line(const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h, const color color) {
		core::ifaces::get_ifaces.surface->draw_set_color(color.r, color.g, color.b, color.a);
		core::ifaces::get_ifaces.surface->draw_line(x, y, w, h);
	}

	void text(const std::int32_t x, const std::int32_t y, const color color, const unsigned long font, const std::string_view text) {
		const auto converted_text = std::wstring(text.begin(), text.end());

		core::ifaces::get_ifaces.surface->draw_set_text_color(color.r, color.g, color.b, color.a);
		core::ifaces::get_ifaces.surface->draw_set_text_font(font);
		core::ifaces::get_ifaces.surface->draw_set_text_pos(x, y);
		core::ifaces::get_ifaces.surface->draw_print_text(converted_text.c_str(), std::wcslen(converted_text.c_str()));
	}

	void circle(const std::int32_t x, const std::int32_t y, const std::int32_t radius, const std::int32_t segments, const color color) {
		core::ifaces::get_ifaces.surface->draw_set_color(color.r, color.g, color.b, color.a);
		core::ifaces::get_ifaces.surface->draw_outlined_circle(x, y, radius, segments);
	}

	void gradient(const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h, const std::int32_t first_alpha, const std::int32_t second_alpha, const color color, const bool horizontal) {
		core::ifaces::get_ifaces.surface->draw_set_color(color.r, color.g, color.b, color.a);
		core::ifaces::get_ifaces.surface->draw_filled_rectangle_fade(x, y, x + w, y + h, first_alpha, second_alpha, horizontal);
	}

	void colored_gradient(const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h, const color first_color, const color second_color, const bool is_horizontal) {
		if (is_horizontal) {
			rectangle(x, y, w, h, first_color);

			for (auto i = 0; i < w; i++)
				rectangle(x + i, y, 1, h, color(second_color.r, second_color.r, second_color.b, i / w * 255));
		}
		else {
			rectangle(x, y, w, h, first_color);

			for (auto i = 0; i < w; i++)
				rectangle(x, y + i, w, 1, color(second_color.r, second_color.r, second_color.b, i / w * 255));
		}
	}

	void get_alpha_value(const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h) {
		for (auto i = 0; i < h / 5; i++) {
			for (auto t = 0; t < w / 5; t++) {
				const auto pixel = static_cast<std::int32_t>(std::round(t));
				const auto line = static_cast<std::int32_t>(std::round(i));
				const auto is_brick_light = line % 2 ? pixel % 2 : pixel % 2 == 0;
				const auto new_color = is_brick_light ? color(60, 60, 60) : color(40, 40, 40);

				rectangle(x + t * 5, y + i * 5, 5, 5, new_color);
			}
		}
	}

	void font_setup() {
		fonts.push_back(CONV_ENUM_TYPE(std::int32_t, enums::font::font_watermark));
		fonts.push_back(CONV_ENUM_TYPE(std::int32_t, enums::font::font_visuals));

		create_font(fonts[CONV_ENUM_TYPE(std::int32_t, enums::font::font_watermark)], "Tahoma", 25, enums::font_flags::dropshadow, false);
		create_font(fonts[CONV_ENUM_TYPE(std::int32_t, enums::font::font_visuals)], "Tahoma", 20, enums::font_flags::dropshadow, false);
	}

	void render_setup(IDirect3DDevice9* device, HWND window) {
		ImGui::CreateContext();
		ImGui_ImplWin32_Init(window);
		ImGui_ImplDX9_Init(device);
	}
}
