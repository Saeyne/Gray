#include "Interface.h"
#include "Containers.h"
#include "ResourceCache.h"

#include <SFML\Graphics.hpp>

namespace base
{
	Label::Label()
	{
		Text = sf::Text("");
	}

	Label::Label(const std::string& s)
	{
		Text = sf::Text(s);
	}

	Label::~Label()
	{
		
	}

	void Label::Update()
	{

	}

	void Label::Render(sf::RenderWindow *rw)
	{
		rw->Draw(Text);
	}

}