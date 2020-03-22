#include "../hooks.hpp"

extern IMGUI_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace cheat::core::hooks::wndproc {
	WNDPROC original = nullptr;

	LRESULT __stdcall hook(HWND window, UINT message, WPARAM wparam, LPARAM lparam)
	{
		switch (message)
		{
		case WM_LBUTTONDOWN:
			sdk::misc::input::pressed[VK_LBUTTON] = true;
			break;
		case WM_LBUTTONUP:
			sdk::misc::input::pressed[VK_LBUTTON] = false;
			break;
		case WM_RBUTTONDOWN:
			sdk::misc::input::pressed[VK_RBUTTON] = true;
			break;
		case WM_RBUTTONUP:
			sdk::misc::input::pressed[VK_RBUTTON] = false;
			break;
		case WM_MBUTTONDOWN:
			sdk::misc::input::pressed[VK_MBUTTON] = true;
			break;
		case WM_MBUTTONUP:
			sdk::misc::input::pressed[VK_MBUTTON] = false;
			break;
		case WM_XBUTTONDOWN:
		case WM_XBUTTONUP:
		{
			auto button = GET_XBUTTON_WPARAM(wparam);
			if (button == XBUTTON1)
				sdk::misc::input::pressed[VK_XBUTTON1] = (message == WM_XBUTTONDOWN);
			else if (button == XBUTTON2)
				sdk::misc::input::pressed[VK_XBUTTON2] = (message == WM_XBUTTONDOWN);
		}
		break;
		case WM_KEYDOWN:
			sdk::misc::input::pressed[wparam] = true;
			break;
		case WM_KEYUP:
			sdk::misc::input::pressed[wparam] = false;
			sdk::misc::input::handle(wparam);
			break;
		default:
			break;
		}

		if (menu::visible && ImGui_ImplWin32_WndProcHandler(window, message, wparam, lparam))
			return true;

		return CallWindowProc(original, window, message, wparam, lparam);
	}
}