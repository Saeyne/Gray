#include "Interface.h"
#include "Containers.h"
#include "ResourceCache.h"

#include <SFML\Graphics.hpp>

namespace base
{
	LinkLabel::LinkLabel()
	{
		Text = sf::Text("NULL");

		NormalColor = sf::Color::Black;
		SelectedColor = sf::Color::Yellow;

		Activated = false;
	}

	LinkLabel::LinkLabel(const std::string& s)
	{
		Text = sf::Text(s);

		NormalColor = sf::Color::Black;
		SelectedColor = sf::Color::Yellow;

		Activated = false;
	}

	LinkLabel::~LinkLabel()
	{
		
	}

	void LinkLabel::Update()
	{
		//update the bounding rectangle
		sf::FloatRect tempRect = Text.GetRect();
		sf::Vector2f temp = Text.GetPosition();
		BoundingRect.TopLeftPoint = base::Vector2F(tempRect.Left, tempRect.Top);
		BoundingRect.Size = base::Vector2F(tempRect.Width, tempRect.Height);

		//change color if the link label has focus
		if (HasFocus)
			Text.SetColor(SelectedColor);
		else
			Text.SetColor(NormalColor);
	}

	void LinkLabel::Render(sf::RenderWindow *rw)
	{
		rw->Draw(Text);
	}

	void LinkLabel::Activate()
	{
		Activated = true;
	}
}