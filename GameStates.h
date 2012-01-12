#ifndef GAMESTATES_H
#define GAMESTATES_H

#include <stack>
#include "Interface.h"
#include "Utility.h"

namespace base
{
	class Engine;			//forward declaration of engine class
	class GameState;		//base state to be inherited by each game state
	class GameStateManager;	//manages all of the game states

	class IntroState;		//first start in the game, splash screens, leads to menu state
	class MenuState;		//the menu at the beginning of the game
	class TestState;		//test state for cj to practice in

	class GameState
	{
	private:
		
	public:
		bool Loaded;
		base::Engine& engine;
		base::InterfaceManager* Interface;
		GameState(base::Engine& eng);
		~GameState() { }
		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;
	};

	class GameStateManager
	{
	private:
		std::stack<GameState *> GameStates;	//the current stack of game states
	public:
		GameStateManager();
		~GameStateManager();
		void PushState(GameState& gs);		//pushes a new state to the top of the stack
		void PopState();					//removes the state at the top of the stack
		void ChangeState(GameState&gs);		//removes all game states from the stack and adds the new one
		GameState& CurrentState();			//returns the state at the top of the stack
	};

	//the splash screen intro state, leads to the menu state
	class IntroState : public GameState
	{
		base::PictureBox* background1;
		base::PictureBox* background2;
		base::PictureBox* background3;
		base::PictureBox* sfmlSplash;
		base::PictureBox* boostSplash;
		base::Timer* splashTimer;
		int splashCount;
	public:
		IntroState(base::Engine& eng) : GameState(eng) { }
		~IntroState();
		void Initialize();
		void Update();
		void Render();
	};

	//the main menu of the game, choose what type of game, or options or quit
	class MenuState : public GameState
	{
		base::Cursor* Cursor;
		base::LinkLabel* singlePlayer;
		base::LinkLabel* multiPlayer;
		base::LinkLabel* Options;
		base::LinkLabel* Quit;

	public:
		MenuState(base::Engine& eng) : GameState(eng) { }
		~MenuState();
		void Initialize();
		void Update();
		void Render();
	};

	//test state for cj to learn in
	class TestState : public GameState
	{

	public:
		TestState(base::Engine& eng) : GameState(eng) { }
		~TestState();
		void Initialize();
		void Update();
		void Render();
	};
}

#endif