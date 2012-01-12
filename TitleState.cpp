#include "GameStates.h"
#include "Engine.h"
#include "Interface.h"
#include "Utility.h"
#include "Collision.h"

namespace base
{
	void TitleState::Initialize()
	{
		//pb1 = new base::PictureBox(base::Sprite(sf::Sprite(engine.ResourceCache->GetTexture("Collision\\Square.png"))));
		//pb1->Move(10, 10);

		//pb2 = new base::PictureBox(base::Sprite(sf::Sprite(engine.ResourceCache->GetTexture("Collision\\Square.png"))));
		//pb2->Move(20, 20);

		//pb3 = new base::PictureBox(base::Sprite(sf::Sprite(engine.ResourceCache->GetTexture("Collision\\Square.png"))));
		//pb3->Move(30, 30);

		//pb4 = new base::PictureBox(base::Sprite(sf::Sprite(engine.ResourceCache->GetTexture("Collision\\Square.png"))));
		//pb4->Move(40, 40);
		
		cursor = new base::Cursor(sf::Sprite(engine.ResourceCache->GetTexture("Crosshair.png")));

		button = new base::Button(sf::Sprite(engine.ResourceCache->GetTexture("tempButton.png")));
		button->Move(400, 400);

		background = new base::PictureBox(base::Sprite(sf::Sprite(engine.ResourceCache->GetTexture("Hero.png"))));
		//background->SetAsBackground(engine.Window);

		lb1 = new base::Label("ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz");
		lb1->Text.SetPosition(0, 200);
		lb1->Text.SetColor(sf::Color::Black);
		lb1->Text.SetScale(0.8, 0.8);
		lb1->Text.SetFont(engine.ResourceCache->GetFont("Fonts\\Lydian.ttf"));

		llbtest = new base::LinkLabel("PUSH HERE");
		llbtest->Text.SetPosition(150, 150);
		llbtest->Text.SetScale(0.8, 0.8);
		llbtest->Text.SetFont(engine.ResourceCache->GetFont("Fonts\\Lydian.ttf"));

		Interface = new base::InterfaceManager();
		//Interface->AddPictureBox(*pb1);
		//Interface->AddPictureBox(*pb2);
		//Interface->AddPictureBox(*pb3);
		//Interface->AddPictureBox(*pb4);
		Interface->AddCursor(*cursor);
		Interface->AddButton(*button);
		Interface->AddControl(*lb1);
		Interface->AddLinkLabel(*llbtest);
		Interface->AddPictureBox(*background);
		
		Interface->Initialize();

		Loaded = true;
	}

	void TitleState::Update()
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
			
			//if enter is pushed, move to the menu state
			if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Keyboard::Return))
				engine.GameStateManager->ChangeState(*engine.MenuState);

			//if the mouse was moved, update the cursor
			if (Event.Type == sf::Event::MouseMoved)
				cursor->Update((sf::Vector2f)sf::Mouse::GetPosition(*engine.Window));

			//if the button was pushed, close the window
			if (button->Pushed)
				engine.Window->Close();
			
			//if the linklabel was activated, close the window
			if (llbtest->Activated)
				engine.Window->Close();
		}

		Interface->Update();
	}

	void TitleState::Render()
	{
		//clear the screen with a color
		engine.Window->Clear(sf::Color(200, 200, 0));

		//draw the interface
		Interface->Render(engine.Window);

		//display the screen
		engine.Window->Display();
	}

	TitleState::~TitleState()
	{

	}

}
