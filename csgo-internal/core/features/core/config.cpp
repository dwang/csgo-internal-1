#include "config.hpp"

namespace cheat::core::features {
	void save_cfg() {
		menu::container["#window"]->save_config("csgo-internal_config.json");

		fgui::handler::call_notification("config has been saved!", fgui::animation_type::LINEAR);
	}

	void load_cfg() {
		menu::container["#window"]->load("csgo-internal_config.json");

		fgui::handler::call_notification("config has been loaded!", fgui::animation_type::LINEAR);
	}
}
