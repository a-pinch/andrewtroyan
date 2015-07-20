#include "game.h"

void game::start_game() {
	unsigned int bet, win; 
	bet = game_player.make_bet();
	game_machine.get_bet(bet);
	game_machine.start_game();
	win = game_machine.return_win();
	game_player.take_win(win);
}