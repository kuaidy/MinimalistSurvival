#ifndef ARMS_H
#define ARMS_H
#include <godot_cpp/classes/sprite2d.hpp>

namespace godot{
    class Arms:public Sprite2D{
        GDCLASS(Arms, Sprite2D)
        public:
            //移动速度
            float moveSpeed=200.0;
            //攻击距离
            float maxDisance=1000;
            //初始位置
            Vector2 initialPosition;
            //是否需要执行释放
            bool isFree=false;
            //移动方向
            Vector2 moveDirection;
            //攻击力
            int attackPower=10;
        protected:
            static void _bind_methods();
        public:
            Arms();
            ~Arms();
            void _ready() override;
            void _process(double delta) override;
            void freeObj();
    };
};
#endif