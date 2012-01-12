#include "Containers.h"

namespace base
{
	Sprite::Sprite(sf::Sprite sfSprite)
		: sf::Sprite(sfSprite)
	{
		DrawLayer = 1;
	}

	Sprite::~Sprite()
	{

	}

	void Sprite::Render(sf::RenderWindow *rw)
	{
		rw->Draw(*this);
	}

}