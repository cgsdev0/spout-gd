#include "register_types.h"

#include <gdextension_interface.h>

#include "spout_gd.h"
#include "spout_texture.h"
#include "spout_viewport.h"

using namespace godot;

void initialize_spout_gd_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }

    GDREGISTER_CLASS(Spout);
    GDREGISTER_CLASS(SpoutTexture);
    GDREGISTER_CLASS(SpoutViewport);
}

void uninitialize_spout_gd_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }
}

extern "C" {
GDExtensionBool GDE_EXPORT spout_gd_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
    godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

    init_obj.register_initializer(initialize_spout_gd_module);
    init_obj.register_terminator(uninitialize_spout_gd_module);
    init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

    return init_obj.init();
}
}
