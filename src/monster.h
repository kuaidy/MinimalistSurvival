#ifndef MONSTER_H
#define MONSTER_H

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {

    class Monster : public Sprite2D  {
        GDCLASS(Monster, Sprite2D)
        public:
            float moveSpeed=50.0;
            int health=10;
            int attackPower=1;
            int attckSpeed=0;
            Vector2 moveDirection;
        protected:
            static void _bind_methods();
        public:
            Monster();
            ~Monster();
            void _ready() override;
            void _process(double delta) override;
    };
}
#endif