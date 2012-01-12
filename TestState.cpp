#include "GameStates.h"
#include "Engine.h"


namespace base
{
	void TestState::Initialize()
	{


		Loaded = true;
	}

	void TestState::Update()
	{
		sf::Event Event;
		while (engine.Window->PollEvent(Event))
		{
			//if the window is closed, end the window
			if (Event.Type == sf::Event::Closed)
				engine.Window->Close();
		}

		
	}

	void TestState::Render()
	{
		//clear the screen with a color
		engine.Window->Clear(sf::Color(200, 0, 200));


		//display the screen
		engine.Window->Display();
	}

	TestState::~TestState()
	{

	}

}
