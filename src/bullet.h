#ifndef BULLET_H
#define BULLET_H
#include <godot_cpp/classes/sprite2d.hpp>
#include <math.h>
#include "arms.h"
namespace godot {
    class Bullet : public Arms {
        GDCLASS(Bullet, Arms)
        public:
            Bullet();
            ~Bullet();
        protected:
            static void _bind_methods();
        public:
            void _ready() override;
            void _process(double delta) override;
    };
}
#endif