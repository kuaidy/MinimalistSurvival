#include "player.h"


#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/input.hpp>

using namespace godot;

Player::Player() {
	// Initialize any variables here.
}

Player::~Player() {
	// Add your cleanup here.
}

void Player::_bind_methods() {
}

void Player::_process(double delta) {
    Vector2 velocity=Vector2(0,0);
    if(Input::get_singleton()->is_action_pressed("ui_left")){
        velocity.x-=1;
    }
    if(Input::get_singleton()->is_action_pressed("ui_right")){
        velocity.x+=1;
    }
    if(Input::get_singleton()->is_action_pressed("ui_up")){
        velocity.y-=1;
    }
    if(Input::get_singleton()->is_action_pressed("ui_down")){
        velocity.y+=1;
    }
    velocity = velocity.normalized() * moveSpeed;
    set_position(get_position()+velocity*delta);
}
void Player::move(){
    
}