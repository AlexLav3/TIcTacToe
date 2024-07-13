#include <iostream>
#include <vector>

void draw();

void introduction(char& player);

bool is_winner(const std::vector<char>& board, char player);

bool filled_up(const std::vector<char>& board);

void set_position(char& player, int& position);

void change_player(char& player);