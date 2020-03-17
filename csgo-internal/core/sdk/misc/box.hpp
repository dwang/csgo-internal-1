#pragma once

namespace cheat::sdk::misc {
	struct box {
		int x, y, w, h;

		box() = default;

		box(int x, int y, int w, int h) {
			this->x = x;
			this->y = y;
			this->w = w;
			this->h = h;
		}
	};
}
