#include "GameStates.h"
#include "Engine.h"
#include "Interface.h"
#include "Utility.h"
#include "Collision.h"

namespace base
{
	void IntroState::Initialize()
	{
		//phases during intro state:
		//black - splash - black (make splash1 transparent) - splash - black - transition to menu state

		//initialize our black window sized pictureboxes
		background1 = new base::PictureBox(base::Sprite(sf::Sprite(engine.ResourceCache->GetTexture("Pixel.png"))));
		background1->SetAsBackground(engine.Window);
		background1->SetColor(sf::Color::Black);
		background2 = new base::PictureBox(*background1);
		background3 = new base::PictureBox(*background1);

		//initialize our splash textures
		sfmlSplash = new base::PictureBox(base::Sprite(sf::Sprite(engine.ResourceCache->GetTexture("SplashScreen\\sfmlLogo.png"))));
		sfmlSplash->Move(100, 100);
		boostSplash = new base::PictureBox(base::Sprite(sf::Sprite(engine.ResourceCache->GetTexture("SplashScreen\\boostLogo.png"))));
		boostSplash->Move(300, 400);

		//add all of the phases to the interface
		Interface = new base::InterfaceManager();

		Interface->AddPictureBox(*background3);
		Interface->AddPictureBox(*boostSplash);
		Interface->AddPictureBox(*background2);
		Interface->AddPictureBox(*sfmlSplash);
		Interface->AddPictureBox(*background1);

		//initialize our timer and counter
		splashTimer = new base::Timer(1000);
		splashCount = 0;

		//finish the introstates initializing
		Loaded = true;
	}

	void IntroState::Update()
	{
		sf::Event Event;
		while (engine.Window->PollEvent(Event))
		{
			//if the window is closed, end the window
			if (Event.Type == sf::Event::Closed)
				engine.Window->Close();
			
			//if enter is pushed, move to the menu state
			if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Keyboard::Return))
				engine.GameStateManager->ChangeState(*engine.MenuState);

		}

		//transition between splash screens
		if (splashTimer->Complete())
		{
			splashCount++;
			splashTimer->Reset();

			if (splashCount == 1)
				background1->SetColor(sf::Color(255, 255, 255, 0));		

			if (splashCount == 2)
				sfmlSplash->SetColor(sf::Color(255, 255, 255, 0));

			if (splashCount == 3)
				background2->SetColor(sf::Color(255, 255, 255, 0));

			if (splashCount == 4)
				boostSplash->SetColor(sf::Color(255, 255, 255, 0));

			if (splashCount == 5)
				engine.GameStateManager->ChangeState(*engine.MenuState);
		}

		Interface->Update();
	}

	void IntroState::Render()
	{
		//clear the screen with a color
		engine.Window->Clear(sf::Color(200, 200, 0));

		//draw the interface
		Interface->Render(engine.Window);

		//display the screen
		engine.Window->Display();
	}

	IntroState::~IntroState()
	{

	}

}
