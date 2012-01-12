#include "GameStates.h"
#include "Engine.h"

namespace base
{
	GameState::GameState(base::Engine& eng)
		: engine(eng)
	{
		//flag that we arent dont loading the gamestate yet
		Loaded = false;

		//initialize the interface manager
//		Interface= new base::InterfaceManager();
	}
}
