#include "Engine.h"

#include <SFML\Graphics.hpp>
#include <boost\filesystem.hpp>

namespace base
{
	Engine::Engine() 
	{

	}

	void Engine::Initialize()
	{
		//setup our logger
		gLogger.Initialize("log.txt");
		gLogger.Write("Engine: Initializing");

		//set up the window
		VideoMode = new sf::VideoMode(800, 600, 32);
		Window = new sf::RenderWindow(*VideoMode, "base");
		gUtility.Initialize(Window);
		Window->ShowMouseCursor(false);
		
		//set up the resorce cache
		sf::String ContentDirectory(boost::filesystem::current_path().string() + "\\GameContent\\");
		ResourceCache = new base::ResourceCache(ContentDirectory);

		//set up the game state manager and game states
		GameStateManager = new base::GameStateManager();
		IntroState = new base::IntroState(*this);
		MenuState = new base::MenuState(*this);
		CJTestState = new base::CJTestState(*this);
		JoshTestState = new base::JoshTestState(*this);

		//set our initial state
		GameStateManager->PushState(*MenuState);

		gLogger.Write("Engine: Initialized");
	}

	void Engine::Run()
	{
		gLogger.Write("Engine: Running");

		//run the program while our window is open
		while (Window->IsOpened())
		{
			GameStateManager->CurrentState().Update();
			GameStateManager->CurrentState().Render();
		}

		gLogger.Write("Engine: Ending");
	}

	Engine::~Engine() 
	{
		gLogger.Write("Engine: Deleting All Components");

		delete VideoMode;
		delete Window;
		delete ResourceCache;
		delete GameStateManager;
		delete IntroState;
		delete MenuState;
		delete CJTestState;
		delete JoshTestState;

		gLogger.Write("Engine: Components Successfully Deleted");
		
	}
}