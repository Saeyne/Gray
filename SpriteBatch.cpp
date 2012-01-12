#include "Containers.h"

namespace base
{
	SpriteBatch::SpriteBatch()
	{

	}

	SpriteBatch::~SpriteBatch()
	{

	}

	void SpriteBatch::AddSprite(Sprite* sprite)
	{
		Sprites.push_back(sprite);
	}

	struct compareDrawOrder
	{
		bool operator() (Sprite* s1, Sprite* s2)
		{
			return s1->DrawLayer < s2->DrawLayer;
		}
	};

	void SpriteBatch::Sort()
	{
		std::sort(Sprites.begin(), Sprites.end(), compareDrawOrder()); 
	}

	void SpriteBatch::Render(sf::RenderWindow *rw)
	{
		for (int count = 0; count < Sprites.size(); count++)
		{
			Sprites[count]->Render(rw);
		}
	}

}