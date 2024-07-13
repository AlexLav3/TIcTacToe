#include <iostream>
#include <vector> 
#include "functions.hpp"

extern std::vector<char> board;
char player;
int position;

int main() {

	introduction(player);
	draw();

	while (!is_winner(board, player) && !filled_up(board)) {
		set_position(player, position);
		draw();
		if (is_winner(board, player)) {
			std::cout << "Player " << player << " wins!\n";
			return 0;
		}

		if (filled_up(board)) {
			return 0;
		}
		change_player(player);
	}


}