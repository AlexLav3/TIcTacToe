#include <iostream>
#include <vector>
#include "functions.hpp"

std::vector<char> board(9, ' '); // Initialize a 1D vector to represent the game board

void introduction(char& player) {
    std::cout << "\nTic tac toe!\n";
    std::cout << "\nPlease choose a character: 'o' or 'x'\n";
    std::cin >> player;
    while (player != 'o' && player != 'x') {
        std::cout << "\nInvalid input. Please choose 'o' or 'x': ";
        std::cin >> player;
    }
}



void draw() {

    std::cout << "     |     |      \n";

    std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";

    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";

    std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";

    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";

    std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
    std::cout << "     |     |      \n";

    std::cout << "\n";
}

void set_position(char& player, int& position) {
    std::cout << "\nPlayer " << player << ", enter your move (1-9): ";
    std::cin >> position;

    // Check if the position is already occupied
    if (board[position - 1] == ' ') {
        // Update the board with the player's choice
        board[position - 1] = player;
    }
    else {
        std::cout << "That position is already occupied. Try again.\n";
        set_position(player, position);  // Call the function again to get a valid move
    }
}

void change_player(char& player) {
    switch (player) {
    case 'x':
        player = 'o';
        break;

    case 'o':
        player = 'x';
        break;
    }
}

bool is_winner(const std::vector<char>& board, char player) {
    if (board[0] == player && board[1] == player && board[2] == player) {
        return true;  // Top row
    }
    else if (board[3] == player && board[4] == player && board[5] == player) {
        return true;  // Middle row
    }
    else if (board[6] == player && board[7] == player && board[8] == player) {
        return true;  // Bottom row
    }
    else if (board[0] == player && board[3] == player && board[6] == player) {
        return true;  // Left column
    }
    else if (board[1] == player && board[4] == player && board[7] == player) {
        return true;  // Middle column
    }
    else if (board[2] == player && board[5] == player && board[8] == player) {
        return true;  // Right column
    }
    else if (board[0] == player && board[4] == player && board[8] == player) {
        return true;  // Diagonal from top-left to bottom-right
    }
    else if (board[2] == player && board[4] == player && board[6] == player) {
        return true;  // Diagonal from top-right to bottom-left
    }

    return false;  // No win condition met
}

bool filled_up(const std::vector<char>& board) {
    for (char position : board) {
        if (position == ' ') {
            return false;  // If any position is empty, the board is not filled up
        }
    }
    return true;  // If no empty positions are found, the board is filled up
}