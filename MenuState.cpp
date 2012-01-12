#include "GameStates.h"
#include "Engine.h"
#include "Collision.h"

namespace base
{
	void MenuState::Initialize()
	{
		//initialize our cursor
		Cursor = new base::Cursor(sf::Sprite(engine.ResourceCache->GetTexture("Crosshair.png")));

		//initialize our link labels
		singlePlayer = new base::LinkLabel("Single Player");
		singlePlayer->Text.SetPosition(100, 100);
		singlePlayer->Text.SetFont(engine.ResourceCache->GetFont("Fonts\\Lydian.ttf"));

		multiPlayer = new base::LinkLabel("Multiplayer");
		multiPlayer->Text.SetPosition(200, 150);
		multiPlayer->Text.SetFont(engine.ResourceCache->GetFont("Fonts\\Lydian.ttf"));

		Options = new base::LinkLabel("Options");
		Options->Text.SetPosition(300, 200);
		Options->Text.SetFont(engine.ResourceCache->GetFont("Fonts\\Lydian.ttf"));

		Quit = new base::LinkLabel("Quit");
		Quit->Text.SetPosition(400, 250);
		Quit->Text.SetFont(engine.ResourceCache->GetFont("Fonts\\Lydian.ttf"));

		//add all of the controls to the interface
		Interface = new base::InterfaceManager();

		Interface->AddCursor(*Cursor);
		Interface->AddLinkLabel(*singlePlayer);
		Interface->AddLinkLabel(*multiPlayer);
		Interface->AddLinkLabel(*Options);
		Interface->AddLinkLabel(*Quit);

		Loaded = true;
	}

	void MenuState::Update()
	{
		sf::Event Event;
		while (engine.Window->PollEvent(Event))
		{
			//if the window is closed, end the window
			if (Event.Type == sf::Event::Closed)
				engine.Window->Close();

			//if F1 is pushed, end the window
			if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Keyboard::F1))
				engine.Window->Close();

			//if the mouse was moved, update the cursor
			if (Event.Type == sf::Event::MouseMoved)
				Cursor->Update((sf::Vector2f)sf::Mouse::GetPosition(*engine.Window));

			//if single player was pushed, switch to single player state
			if (singlePlayer->Activated)
				engine.Window->Close();

			//if multiplayer was pushed, switch to multiplayer state
			if (multiPlayer->Activated)
				engine.Window->Close();

			//if options was pushed, switch to options state?
			if (Options->Activated)
				engine.Window->Close();

			//if quit was pushed, end the game
			if (Quit->Activated)
				engine.Window->Close();

		}

		Interface->Update();
	}

	void MenuState::Render()
	{
		//clear the screen with a color
		engine.Window->Clear(sf::Color(200, 200, 0));

		//draw the interface
		Interface->Render(engine.Window);

		//display the screen
		engine.Window->Display();
	}

	MenuState::~MenuState()
	{

	}

}
