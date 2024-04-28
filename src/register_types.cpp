#include "register_types.h"

#include "main.h"
#include "player.h"
#include "arms.h"
#include "bullet.h"
#include "monster.h"
#include "monster_triangle.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_game_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
    ClassDB::register_class<Main>();
	ClassDB::register_class<Player>();
    ClassDB::register_class<Arms>();
    ClassDB::register_class<Bullet>();
    ClassDB::register_class<Monster>();
    ClassDB::register_class<MonsterTriangle>();
}

void uninitialize_game_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C" {
    // Initialization.
    GDExtensionBool GDE_EXPORT minimalistsurvival_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
        godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);
        init_obj.register_initializer(initialize_game_module);
        init_obj.register_terminator(uninitialize_game_module);
        init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);
        return init_obj.init();
    }
}