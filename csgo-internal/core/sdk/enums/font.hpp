#pragma once

namespace cheat::sdk::enums {
	enum struct font {
		font_watermark,
		font_visuals
	};

	enum font_flags
	{
		none,
		italic = 0x001,
		underline = 0x002,
		strikeout = 0x004,
		symbol = 0x008,
		antialias = 0x010,
		gaussianblur = 0x020,
		rotary = 0x040,
		dropshadow = 0x080,
		additive = 0x100,
		outline = 0x200,
		custom = 0x400,
		bitmap = 0x800
	};
}