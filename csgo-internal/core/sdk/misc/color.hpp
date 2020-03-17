#pragma once

#include <cstdint>
#include <d3d9.h>

namespace cheat::sdk::misc {
	struct color {
		int r, g, b, a;

		color() = default;

		color(int r, int g, int b, int a = 255) {
			this->r = r;
			this->g = g;
			this->b = b;
			this->a = a;
		}

		color(std::uint32_t color) {
			this->r = (color >> 16) & 0xff;
			this->g = (color >> 8) & 0xff;
			this->b = (color & 0xff);
			this->a = (color >> 24) & 0xff;
		}

		color from_uint(std::uint32_t uint) {
			return color(uint);
		}

		D3DCOLOR from_color(color col) {
			return D3DCOLOR_ARGB(col.a, col.r, col.g, col.b);
		}
	};
}
