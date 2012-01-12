#include "Interface.h"
#include "Containers.h"
#include "ResourceCache.h"

#include <SFML\Graphics.hpp>

namespace base
{
	PictureBox::PictureBox(base::Sprite sprite)
		: Sprite(sprite)
	{
		BoundingRect.Size.Y = sprite.GetSize().y;
		BoundingRect.Size.X = sprite.GetSize().x;
		BoundingRect.TopLeftPoint.Y = sprite.GetPosition().y;
		BoundingRect.TopLeftPoint.X = sprite.GetPosition().x;

	}

	void PictureBox::Update()
	{
		BoundingRect.TopLeftPoint.Y = this->GetPosition().y;
		BoundingRect.TopLeftPoint.X = this->GetPosition().x;
	}

	void PictureBox::Render(sf::RenderWindow *rw)
	{
		if (this->Visible)
			rw->Draw(*this);
	}

	void PictureBox::SetAsBackground(sf::RenderWindow *rw)
	{
		this->SetPosition(0, 0);
		this->Resize(rw->GetWidth(), rw->GetHeight());
	}

}