#include "player.h"
#include "bullet.h"
#include "arms.h"
#include "monster_triangle.h"
#include <godot_cpp/classes/timer.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/classes/path_follow2d.hpp>
#include <godot_cpp/classes/random_number_generator.hpp>
#include <math.h>
#include <godot_cpp/templates/vector.hpp>

namespace godot{
    class Main:public Node{
        GDCLASS(Main, Node)
        private:
            Player *m_Player;
            Timer *m_BulletTimer;
            Timer *m_MonsterTriangleTimer;
            //子弹场景
            // Ref<Resource> m_BulletScene;
            Ref<PackedScene> m_BulletScene;
            //怪物场景(三角形)
            Ref<PackedScene> m_MonsterTriangleScene;
            //怪物
            Vector<MonsterTriangle*> m_MonsterTriangles;
        protected:
            static void _bind_methods();
        public:
            Main();
            ~Main();
            void _process(double delta) override;
            void _ready() override;
            void _on_bullet_timer_timeout();
            void _on_monster_timer_timeout();
            Ref<Resource> get_bullet_scene() const;
            void set_bullet_scene(const Ref<Resource> bulletScene);
            Ref<Resource> get_monster_triangle_scene() const;
            void set_monster_triangle_scene(const Ref<Resource> monsterTrianleScene);
            //怪物移动方向
            void monster_move_direction();
            //子弹移动方向
            void bullet_move_direction();
            //敌人死亡释放
            void free_monster();
    };
};
