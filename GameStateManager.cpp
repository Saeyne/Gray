#include "GameStates.h"

#include "Utility.h"

namespace base
{
	

	GameStateManager::GameStateManager()
	{
		gLogger.Write("GameStateManager: Initialized");
	}

	GameStateManager::~GameStateManager()
	{

	}

	void GameStateManager::PushState(GameState& gs)
	{
		if (!gs.Loaded)
			gs.Initialize();
		GameStates.push(&gs);
	}

	void GameStateManager::PopState()
	{
		GameStates.pop();
	}

	void GameStateManager::ChangeState(GameState& gs)
	{
		while (!GameStates.empty())
			GameStates.pop();
		
		if (!gs.Loaded)
			gs.Initialize();
		GameStates.push(&gs);
	}

	GameState& GameStateManager::CurrentState()
	{
		return *GameStates.top();
	}
}