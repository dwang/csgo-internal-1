#pragma once

#include <thread>

#include "../ifaces/ifaces.hpp"
#include "../mem/mem.hpp"
#include "../hooks/hooks.hpp"
#include "../menu/menu.hpp"
#include "../sdk/sdk.hpp"

namespace cheat::core::main {
	extern BOOL WINAPI detach();
	extern DWORD WINAPI attach(LPVOID);
}
