#include "bullet.h"

using namespace godot;

Bullet::Bullet(){

}

Bullet::~Bullet(){

}
void Bullet::_bind_methods() {
}
void Bullet::_ready(){
    initialPosition=get_position();
    set_rotation(moveDirection.angle()+Math_PI/4);
}
void Bullet::_process(double delta){
    set_position(get_position()+moveDirection*moveSpeed*delta);
    if(isFree){
        float distance=initialPosition.distance_to(get_position());
        if(distance>maxDisance){
            queue_free();
        }
    }
}