#pragma once

#include "capture_iface.hpp"
#include "netvar_tree.hpp"
#include "vfunc_from_index.hpp"
#include "../../dependencies/minhook/MinHook.h"

#define REGISTERS \
	std::uintptr_t ecx, std::uintptr_t edx

#define PAD(variable_name, size) \
	std::byte variable_name[size]

#define CONV_ENUM_TYPE(type, enum_class) \
    static_cast<type>(enum_class)

#define CAPTURE_IFACE(var_name, iface_struct, iface_module, iface_name) \
	iface_struct* var_name = cheat::sdk::misc::capture_iface<iface_struct*>(iface_module, iface_name)

#define MEM_PTR(var_name, iface_struct, iface_ptr, base, offset) \
	iface_struct* var_name = **reinterpret_cast<iface_struct***>((*reinterpret_cast<std::uintptr_t**>(iface_ptr))[base] + offset)

#define SETUP_HOOK(target, hook, original) \
	MH_CreateHook(target, &hook, reinterpret_cast<void**>(&original))

#define HOOK_TARGET(iface_ptr, index) \
	sdk::misc::vfunc_from_index<void*>(iface_ptr, index)

#define NETVAR(func_name, type, ...) \
	type& func_name { \
		return *reinterpret_cast<type*>(reinterpret_cast<std::uintptr_t>(this) + misc::get_netvar_tree->get_offset(__VA_ARGS__)); \
	};

#define OFFSET(func_name, type, offset) \
	type& func_name { \
		return *reinterpret_cast<type*>(std::uintptr_t(this) + offset); \
	};

#define VFUNC(func_name, index, type, ...) \
	auto func_name { \
		return cheat::sdk::misc::vfunc_from_index<type>(this, index)(this, __VA_ARGS__); \
	};
