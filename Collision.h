#ifndef COLLISION_H
#define COLLISION_H

#include <SFML\Graphics.hpp>
#include "Containers.h"

namespace base
{
	class Collision
	{
		Collision() { }
		~Collision() { }
	public:
		static bool SpriteCollision(const base::Sprite& object1, const base::Sprite& object2);
		static sf::IntRect GetRectFromSprite(const base::Sprite& sprite);

	};
}

#endif