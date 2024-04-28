#ifndef PLAYER_H
#define PLAYER_H

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {
	class Player : public Sprite2D {
		GDCLASS(Player, Sprite2D)
	private:
		float moveSpeed=200;
		int level=1;
		int health=10;
	protected:
		static void _bind_methods();
	public:
		Player();
		~Player();
		void _process(double delta) override;
		void move();
	};
}
#endif