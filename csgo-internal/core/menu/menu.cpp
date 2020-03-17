#include "menu.hpp"

namespace cheat::core::menu {
	void menu_setup() {
		style.Alpha = 1.0f;
		style.WindowPadding = ImVec2(10, 10);
		style.WindowMinSize = ImVec2(100, 100);
		style.WindowRounding = 0.0f;
		style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
		style.ChildRounding = 0.0f;
		style.FramePadding = ImVec2(5, 5);
		style.FrameRounding = 0.0f;
		style.FrameBorderSize = 1.0f;
		style.ItemSpacing = ImVec2(5, 5);
		style.ItemInnerSpacing = ImVec2(4, 4);
		style.TouchExtraPadding = ImVec2(0, 0);
		style.IndentSpacing = 21.0f;
		style.ColumnsMinSpacing = 6.0f;
		style.ScrollbarSize = 16.0f;
		style.ScrollbarRounding = 9.0f;
		style.GrabMinSize = 10.0f;
		style.GrabRounding = 0.0f;
		style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
		style.DisplayWindowPadding = ImVec2(22, 22);
		style.DisplaySafeAreaPadding = ImVec2(4, 4);
		style.AntiAliasedLines = true;
		style.AntiAliasedFill = true;
		style.CurveTessellationTol = 1.25f;

		style.Colors[ImGuiCol_Text] = ImVec4(0.86f, 0.93f, 0.89f, 0.78f);
		style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.86f, 0.93f, 0.89f, 0.28f);
		style.Colors[ImGuiCol_WindowBg] = ImVec4(0.13f, 0.14f, 0.17f, 1.00f);
		style.Colors[ImGuiCol_Border] = ImVec4(0.31f, 0.31f, 1.00f, 0.00f);
		style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		style.Colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
		style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.15f, 0.60f, 0.78f, 0.78f);
		style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
		style.Colors[ImGuiCol_TitleBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
		style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.20f, 0.22f, 0.27f, 0.75f);
		style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
		style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.20f, 0.22f, 0.27f, 0.47f);
		style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
		style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.09f, 0.15f, 0.16f, 1.00f);
		style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.15f, 0.60f, 0.78f, 0.78f);
		style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
		style.Colors[ImGuiCol_CheckMark] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
		style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.47f, 0.77f, 0.83f, 0.14f);
		style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
		style.Colors[ImGuiCol_Button] = ImVec4(0.47f, 0.77f, 0.83f, 0.14f);
		style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.15f, 0.60f, 0.78f, 0.86f);
		style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
		style.Colors[ImGuiCol_Header] = ImVec4(0.15f, 0.60f, 0.78f, 0.76f);
		style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.15f, 0.60f, 0.78f, 0.78f);
		style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.15f, 0.60f, 0.78f, 1.0f); // 
		style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.47f, 0.77f, 0.83f, 0.04f);
		style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.15f, 0.60f, 0.78f, 0.78f);
		style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
		style.Colors[ImGuiCol_PlotLines] = ImVec4(0.86f, 0.93f, 0.89f, 0.63f);
		style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
		style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.86f, 0.93f, 0.89f, 0.63f);
		style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
		style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.15f, 0.60f, 0.78f, 0.43f);
		style.Colors[ImGuiCol_PopupBg] = ImVec4(0.20f, 0.22f, 0.27f, 0.9f);
		style.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.20f, 0.22f, 0.27f, 0.73f);

		render_tab["aim"] = []() {
			ImGui::Checkbox("backtrack", &vars::aim::backtrack);
			if (vars::aim::backtrack) {
				ImGui::SameLine();
				ImGui::SliderInt("ticks", &vars::aim::backtrack_ticks, 1, 12);
			}
		};

		render_tab["visuals"] = []() {
			const char* items[] = { "off", "on", "dead" };

			if (ImGui::BeginCombo("##esp", items[vars::visuals::esp_mode])) {
				for (int n = 0; n < IM_ARRAYSIZE(items); n++) {
					bool is_selected = (items[vars::visuals::esp_mode] == items[n]);
					if (ImGui::Selectable(items[n], is_selected)) {
						vars::visuals::esp_mode = n;
						ImGui::SetItemDefaultFocus();
					}
				}
				ImGui::EndCombo();
			}

			if (vars::visuals::esp_mode != 0) {
				ImGui::Checkbox("box esp", &vars::visuals::box_esp);
				ImGui::SameLine();
				ImGui::Checkbox("name esp", &vars::visuals::name_esp);
				ImGui::SameLine();
				ImGui::Checkbox("health esp", &vars::visuals::health_esp);
				ImGui::SameLine();
				ImGui::Checkbox("armor esp", &vars::visuals::armor_esp);
				ImGui::SameLine();
				ImGui::Checkbox("scoped esp", &vars::visuals::scoped_esp);
			}

			ImGui::Checkbox("chams", &vars::visuals::chams);
			if (vars::visuals::chams) {
				ImGui::SameLine();
				ImGui::Checkbox("chams ignore z", &vars::visuals::chams_ignore_z);
			}

			ImGui::Checkbox("flash", &vars::visuals::flash_alpha);
			if (vars::visuals::flash_alpha) {
				ImGui::SameLine();
				ImGui::SliderFloat("alpha", &vars::visuals::flash_alpha_value, 0.0f, 255.0f);
			}

			ImGui::Checkbox("view model", &vars::visuals::view_model_fov);
			if (vars::visuals::view_model_fov) {
				ImGui::SameLine();
				ImGui::SliderFloat("fov", &vars::visuals::view_model_fov_value, 0.0f, 68.0f);
			}
		};

		render_tab["misc"] = []() {
			ImGui::Checkbox("bunnyhop", &vars::misc::bunnyhop);
			ImGui::Checkbox("rank reveal", &vars::misc::rank_reveal);
			ImGui::Checkbox("grenade preview", &vars::misc::grenade_preview);
			ImGui::Checkbox("watermark", &vars::misc::watermark);

			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::Spacing();

			if (ImGui::Button("disconnect to lobby", ImVec2(200, 30)))
				features::disconnect_to_lobby();

			if (ImGui::Button("unload", ImVec2(100, 30)))
				cheat::core::vars::misc::unload = true;
		};

		render_tab["skins"] = []() {
			ImGui::Text("skins");
		};
	}

	void render() {
		const std::vector<std::string> tabs = { "aim", "visuals", "misc", "skins" };
		constexpr int width = 650;
		ImGui::GetStyle() = style;

		ImGui::SetNextWindowSize({ static_cast<float>(width), static_cast<float>(tabs.size()) * 50 + 40 + 3 });

		if (ImGui::Begin("csgo-internal", &visible, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize)) {
			ImGui::Columns(2, "##cols", false);
			ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, { 0, 0 });

			for (unsigned i = 0; i < tabs.size(); i++) {
				if (i == active_tab)
					ImGui::GetStyle().Colors[ImGuiCol_Button] = ImVec4(0.20f, 0.70f, 0.95f, 1.00f);
				else
					ImGui::GetStyle().Colors[ImGuiCol_Button] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);

				if (ImGui::Button(tabs[i].c_str(), ImVec2(150, 50)))
					active_tab = i;
			}

			ImGui::PopStyleVar();
			ImGui::SetColumnOffset(0, -(width / 2 - 150 - 20));
			ImGui::NextColumn();
			render_tab[tabs[active_tab]]();
			ImGui::End();
		}
	}
}
