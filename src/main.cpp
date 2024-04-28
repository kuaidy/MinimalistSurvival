#include "main.h"
using namespace godot;
Main::Main(){

}
Main::~Main(){

}
void Main::_ready(){
    m_Player=get_node<Player>("Player/Player");
    m_BulletTimer=get_node<Timer>("BulletTimer");
    m_MonsterTriangleTimer=get_node<Timer>("MonsterTimer");
}

void Main::_process(double delta){
    monster_move_direction();
    free_monster();
}

void Main::_bind_methods(){
    ClassDB::bind_method(D_METHOD("get_bullet_scene"),&Main::get_bullet_scene);
    ClassDB::bind_method(D_METHOD("set_bullet_scene","bulletScene"),&Main::set_bullet_scene);
    ClassDB::add_property("Main", PropertyInfo(Variant::OBJECT, "m_BulletScene"), "set_bullet_scene", "get_bullet_scene");

    ClassDB::bind_method(D_METHOD("get_monster_triangle_scene"),&Main::get_monster_triangle_scene);
    ClassDB::bind_method(D_METHOD("set_monster_triangle_scene","monsterTrianleScene"),&Main::set_monster_triangle_scene);
    ClassDB::add_property("Main", PropertyInfo(Variant::OBJECT, "m_MonsterTriangleScene"), "set_monster_triangle_scene", "get_monster_triangle_scene");
    
    ClassDB::bind_method(D_METHOD("_on_bullet_timer_timeout"),&Main::_on_bullet_timer_timeout);
    ClassDB::bind_method(D_METHOD("_on_monster_timer_timeout"),&Main::_on_monster_timer_timeout);

    // ClassDB::bind_method(D_METHOD("get_test"),&Main::get_test);
    // ClassDB::bind_method(D_METHOD("set_test","num"),&Main::set_test);
    // ClassDB::add_property("Main",PropertyInfo(Variant::INT,"test"),"set_test","get_test");
}

Ref<Resource> Main::get_bullet_scene() const{
    return m_BulletScene;
}
void Main::set_bullet_scene(const Ref<Resource> bulletScene){
    m_BulletScene=bulletScene;
}

Ref<Resource> Main::get_monster_triangle_scene() const{
    return m_MonsterTriangleScene;
}
void Main::set_monster_triangle_scene(const Ref<Resource> monsterTrianleScene){
    m_MonsterTriangleScene=monsterTrianleScene;
}

void Main::_on_bullet_timer_timeout(){
    m_BulletTimer->start();
    Node *bulletNode = m_BulletScene->instantiate();
    Bullet *bullet = bulletNode->get_node<Bullet>("Bullet");
    if(m_Player&&bullet){
        bullet->set_position(m_Player->get_global_position());
        int currentMonsterIndex=0;
        float minDistance=1000000;
        for(int i=0;i<m_MonsterTriangles.size();++i){
            float currentDistance=m_MonsterTriangles[i]->get_global_position().distance_to(m_Player->get_global_position());
            if(currentDistance<minDistance){
                minDistance=currentDistance;
                currentMonsterIndex=i;
            }
        }
        bullet->moveDirection=(m_MonsterTriangles[currentMonsterIndex]->get_global_position()-m_Player->get_global_position()).normalized();
        bullet->freeObj();
    }
    add_child(bulletNode);
}

void Main::_on_monster_timer_timeout(){
    m_MonsterTriangleTimer->start();
    Node *monsterTriangleScene = m_MonsterTriangleScene->instantiate();
    PathFollow2D *monsterSpawnLocation = get_node<PathFollow2D>("MonsterPath/MonsterSpawnLocation");
    RandomNumberGenerator randomNumberGenerator;
    monsterSpawnLocation->set_progress_ratio(randomNumberGenerator.randf());
    MonsterTriangle *monsterTriangle=monsterTriangleScene->get_node<MonsterTriangle>("MonsterTriangle");
    m_MonsterTriangles.push_back(monsterTriangle);
    if(monsterTriangle){
        monsterTriangle->moveDirection=(m_Player->get_global_position() - monsterSpawnLocation->get_global_position()).normalized();
        monsterTriangle->set_position(monsterSpawnLocation->get_global_position());
    }
    add_child(monsterTriangleScene);
}

void Main::monster_move_direction(){
    for(int i=0;i<m_MonsterTriangles.size();++i){
        m_MonsterTriangles[i]->moveDirection=(m_Player->get_global_position() - m_MonsterTriangles[i]->get_global_position()).normalized();
    }
}

void Main::free_monster(){
    for(int i=0;i<m_MonsterTriangles.size();++i){
        if(m_MonsterTriangles[i]->health<=0){
            delete m_MonsterTriangles[i];
        }
    }
}
