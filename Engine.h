#ifndef ENGINE_H
#define ENGINE_H

#include "Utility.h"
#include "GameStates.h"
#include "ResourceCache.h"

#include <SFML\Graphics.hpp>

namespace base
{
	class Engine
	{
	public:
		sf::VideoMode*			VideoMode;
		sf::RenderWindow*		Window;

		base::ResourceCache*	ResourceCache;
		
		base::GameStateManager* GameStateManager;

		base::IntroState*		IntroState;
		base::MenuState*		MenuState;
		base::TestState*		TestState;

		Engine();
		~Engine();
		void Initialize();
		void Run();
	};
}

#endif