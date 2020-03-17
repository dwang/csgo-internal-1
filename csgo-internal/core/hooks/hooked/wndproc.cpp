#include "../hooks.hpp"

extern IMGUI_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace cheat::core::hooks::wndproc {
	WNDPROC original = nullptr;

	LRESULT __stdcall hook(HWND window, UINT message, WPARAM wparam, LPARAM lparam)
	{
		switch (message)
		{
		case WM_LBUTTONDOWN:
			cheat::sdk::misc::input::pressed[VK_LBUTTON] = true;
			break;
		case WM_LBUTTONUP:
			cheat::sdk::misc::input::pressed[VK_LBUTTON] = false;
			break;
		case WM_RBUTTONDOWN:
			cheat::sdk::misc::input::pressed[VK_RBUTTON] = true;
			break;
		case WM_RBUTTONUP:
			cheat::sdk::misc::input::pressed[VK_RBUTTON] = false;
			break;
		case WM_MBUTTONDOWN:
			cheat::sdk::misc::input::pressed[VK_MBUTTON] = true;
			break;
		case WM_MBUTTONUP:
			cheat::sdk::misc::input::pressed[VK_MBUTTON] = false;
			break;
		case WM_XBUTTONDOWN:
		case WM_XBUTTONUP:
		{
			auto button = GET_XBUTTON_WPARAM(wparam);
			if (button == XBUTTON1)
				cheat::sdk::misc::input::pressed[VK_XBUTTON1] = (message == WM_XBUTTONDOWN);
			else if (button == XBUTTON2)
				cheat::sdk::misc::input::pressed[VK_XBUTTON2] = (message == WM_XBUTTONDOWN);
		}
		break;
		case WM_KEYDOWN:
			cheat::sdk::misc::input::pressed[wparam] = true;
			break;
		case WM_KEYUP:
			cheat::sdk::misc::input::pressed[wparam] = false;
			cheat::sdk::misc::input::handle(wparam);
			break;
		default:
			break;
		}

		if (menu::visible && ImGui_ImplWin32_WndProcHandler(window, message, wparam, lparam))
			return true;

		return CallWindowProc(cheat::core::hooks::wndproc::original, window, message, wparam, lparam);
	}
}