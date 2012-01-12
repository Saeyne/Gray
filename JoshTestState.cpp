#include "GameStates.h"
#include "Engine.h"


namespace base
{
	void JoshTestState::Initialize()
	{


		Loaded = true;
	}

	void JoshTestState::Update()
	{
		sf::Event Event;
		while (engine.Window->PollEvent(Event))
		{
			//if the window is closed, end the window
			if (Event.Type == sf::Event::Closed)
				engine.Window->Close();
		}

		
	}

	void JoshTestState::Render()
	{
		//clear the screen with a color
		engine.Window->Clear(sf::Color(200, 0, 200));


		//display the screen
		engine.Window->Display();
	}

	JoshTestState::~JoshTestState()
	{

	}

}
