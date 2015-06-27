#pragma once

#include "slot_machine.h"
#include "player.h"

class game {
private:
	slot_machine& game_machine;
	player& game_player;
public:
	//ctor
	game(slot_machine& machine, player& player) : game_machine(machine), game_player(player) {};
	~game() {};
	
	//method
	void start_game();
};

