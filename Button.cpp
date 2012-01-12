#include "Interface.h"

#include "Utility.h"
#include "Containers.h"

#include <SFML\Graphics.hpp>

namespace base
{

	Button::Button(base::Sprite sprite)
		: Sprite(sprite), timer(125)
	{
		Pushed = false;
		sf::Vector2f temp = sprite.GetSize();
		size = Vector2F(temp.x, temp.y);
		size.Y /= 2;

		BoundingRect.Size.Y = size.Y;
		BoundingRect.Size.X = size.X;
		BoundingRect.TopLeftPoint.Y = sprite.GetPosition().y;
		BoundingRect.TopLeftPoint.X = sprite.GetPosition().x;
	}

	Button::~Button()
	{

	}

	void Button::Update()
	{
		if (this->Enabled)
		{

			BoundingRect.TopLeftPoint.Y = this->GetPosition().y;
			BoundingRect.TopLeftPoint.X = this->GetPosition().x;

			if (timer.Complete())
				Pushed = false;
		}
	}

	void Button::Render(sf::RenderWindow *rw)
	{
		if (!Pushed)
			//set the sub-rect to the top half of the button texture (unpushed)
			this->SetSubRect(sf::IntRect(0, 0, size.X, size.Y));
		else
			//draw the pushed version
			this->SetSubRect(sf::IntRect(0, size.Y, size.X, size.Y));;

		if (this->Visible)
		{
			rw->Draw(*this);
		}
	}

	void Button::Push()
	{
		if (this->Enabled)
		{
			timer.Reset();
			Pushed = true;
		}
	}

	void Button::SetTimer(float milliseconds)
	{
		timer.SetTime(milliseconds);
	}
}