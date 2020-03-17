#pragma once

#include <memory>
#include <cstdint>

#include "../ifaces/ifaces.hpp"
#include "../mem/mem.hpp"
#include "../features/features.hpp"
#include "../sdk/sdk.hpp"
#include "../../dependencies/minhook/MinHook.h"

namespace cheat::core::hooks {
	namespace create_move {
		using fn = bool(__thiscall*)(std::uintptr_t, float, sdk::ifaces::user_cmd*);
		extern bool __fastcall hook(REGISTERS, float, sdk::ifaces::user_cmd*);
		extern fn original;
	}

	namespace emit_sound {
		using fn = void(__thiscall*)(std::uintptr_t, sdk::ifaces::sound_data);
		extern void __fastcall hook(REGISTERS, sdk::ifaces::sound_data);
		extern fn original;
	}

	namespace end_scene {
		using fn = long(__thiscall*)(std::uintptr_t, IDirect3DDevice9*);
		extern long __fastcall hook(REGISTERS, IDirect3DDevice9* device);
		extern fn original;
	}

	namespace frame_stage_notify {
		using fn = void(__thiscall*)(std::uintptr_t, sdk::enums::client_frame_stage);
		extern void __fastcall hook(REGISTERS, sdk::enums::client_frame_stage);
		extern fn original;
	}

	namespace in_key_event {
		using fn = int(__thiscall*)(std::uintptr_t, int, int, const char*);
		extern int __fastcall hook(REGISTERS, int, int, const char*);
		extern fn original;
	}

	namespace lock_cursor {
		using fn = void(__thiscall*)(std::uintptr_t);
		extern void __fastcall hook(REGISTERS);
		extern fn original;
	}

	namespace override_view {
		using fn = void(__thiscall*)(std::uintptr_t, sdk::ifaces::view_setup*);
		extern void __fastcall hook(REGISTERS, sdk::ifaces::view_setup*);
		extern fn original;
	}

	namespace paint_traverse {
		using fn = void(__thiscall*)(std::uintptr_t, std::int32_t, bool, bool);
		extern void __fastcall hook(REGISTERS, std::int32_t, bool, bool);
		extern fn original;
	}

	namespace reset {
		using fn = long(__thiscall*)(std::uintptr_t, IDirect3DDevice9*, D3DPRESENT_PARAMETERS*);
		extern long __fastcall hook(REGISTERS, IDirect3DDevice9* device, D3DPRESENT_PARAMETERS* presentation_parameters);
		extern fn original;
	}

	namespace scene_end {
		using fn = void(__thiscall*)(std::uintptr_t);
		extern void __fastcall hook(REGISTERS);
		extern fn original;
	}

	namespace wndproc {
		extern LRESULT __stdcall hook(HWND window, UINT message, WPARAM wparam, LPARAM lparam);
		extern WNDPROC original;
	}

	extern void hooks_create();
	extern void hooks_destroy();
}
