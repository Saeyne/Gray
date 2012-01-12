#include "Interface.h"
#include "Containers.h"

#include <SFML\Graphics.hpp>

namespace base
{
	Cursor::Cursor(base::Sprite sprite)
		: PictureBox(sprite)
	{
		
	}

	Cursor::~Cursor()
	{

	}

	void Cursor::Update(sf::Vector2f position)
	{
		this->SetPosition(position);

		BoundingRect.TopLeftPoint.Y = this->GetPosition().y;
		BoundingRect.TopLeftPoint.X = this->GetPosition().x;
		BoundingRect.polygon.SetPosition(position);
	}

	void Cursor::Render(sf::RenderWindow *rw)
	{
		if (this->Visible)
		{
			rw->Draw(*this);
		}
	}


}