#pragma once

#include <array>
#include <map>

namespace cheat::sdk::misc::input {
	using fn = void(*)();

	inline std::map<int, fn> functions;
	inline std::array<bool, 256> pressed;

	static void add(int key, fn function) {
		functions[key] = function;
	}

	static void handle(int key) {
		if (functions.count(key))
			functions[key]();
	}
};
