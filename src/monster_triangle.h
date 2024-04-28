#ifndef MONSTER_TRIANGLE_H
#define MONSTER_TRIANGLE_H

#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/variant/rid.hpp>
#include <godot_cpp/classes/node2d.hpp>

#include "monster.h"
#include <stdio.h>
#include "bullet.h"
#include "arms.h"

namespace godot {

    class MonsterTriangle : public Monster {
        GDCLASS(MonsterTriangle, Monster)
        protected:
            static void _bind_methods();
        public:
            MonsterTriangle();
            ~MonsterTriangle();
            void _ready() override;
            void _process(double delta) override;
            void _on_area_entered(Node *body);
            
    };
}
#endif