#include "monster_triangle.h"

using namespace godot;

MonsterTriangle::MonsterTriangle(){}
MonsterTriangle::~MonsterTriangle(){}
void MonsterTriangle::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_on_area_entered"),&MonsterTriangle::_on_area_entered);
}
void MonsterTriangle::_ready(){
}
void MonsterTriangle::_process(double delta){
    set_position(get_position()+moveDirection*moveSpeed*delta);
}
void MonsterTriangle::_on_area_entered(Node *body){
    // Arms *arms = body->get_node<Bullet>("Bullet");
    // health-=arms->attackPower;
    health-=10;
}