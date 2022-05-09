/*
CPSC 3750 Rocky Au
Class to represent states in the search algorithm
April, 2022

Source file for the board class. The class enforces the rules of the game and plays it.
*/

#include <iostream>
#include "Board.h"

Board::Board(){}

void Board::displayBoard() {
	std::cout << board[0] << "|" << board[1] << "|" << board[2] << std::endl;
	std::cout << "-+-+-" << std::endl;
	std::cout << board[3] << "|" << board[4] << "|" << board[5] <<  std::endl;
	std::cout << "-+-+-" << std::endl;
	std::cout << board[6] << "|" << board[7] << "|" << board[8] << std::endl;
	std::cout << std::endl;
}

bool Board::checkDraw() {
	if (checkWinner('X') || checkWinner('O')) return false;
	for (auto p : board) {
		if (p == ' ') {
			return false;
		}
	}
	return true;
}

bool Board::checkWinner(char c) {
	if (
		((board[0] == board[1]) && (board[1] == board[2]) && (board[0] == c)) ||
		((board[3] == board[4]) && (board[4] == board[5]) && (board[3] == c)) ||
		((board[6] == board[7]) && (board[7] == board[8]) && (board[6] == c)) ||
		((board[0] == board[3]) && (board[3] == board[6]) && (board[0] == c)) ||
		((board[1] == board[4]) && (board[4] == board[7]) && (board[1] == c)) ||
		((board[2] == board[5]) && (board[5] == board[8]) && (board[2] == c)) ||
		((board[0] == board[4]) && (board[4] == board[8]) && (board[0] == c)) ||
		((board[2] == board[4]) && (board[4] == board[6]) && (board[2] == c))
		) {
		return true;
	}
	return false;
}


bool Board::checkEnd() {
	if (checkWinner('X'))return true;
	if (checkWinner('O'))return true;
	if (checkDraw()) return true;
	return false;
}

bool Board::checkEnd(char c) {
	if (checkDraw() || checkWinner(c)) {
		return true;
	}
	return false;
}

bool Board::validMove(int i) {
	if (board[i] == ' ') {
		return true;
	}
	return false;
}

void Board::playerMove() {
	int input = -1;
	while(!(validMove (input))) {
		std::cout << "\nWhat is your move? (0-8): " << std:: flush;
		std::cin >> input;
	}
	board[input] = player;
}

void Board::play() {
	AIPlayer* bot = new AIPlayer();
	char currPlayer = player;
	turn = 0;
	displayBoard();
	while(!(checkEnd(currPlayer))) {
		turn++;
		currPlayer = player;
		playerMove();
		displayBoard();
		if (checkEnd()) {
			break;
		}
		currPlayer = aiPlayer;
		aiMove();
		std::cout << "AI made the move: " << std::endl;
		displayBoard();
		turn++;
		if (checkEnd()) {
			break;
		}
	}
	if(checkWinner('X')) {
		std::cout << "\nYou did the impossible." << std::endl;
	}
	if(checkWinner('O')) {
		std::cout << "\nAI won. A natural conclusion." << std::endl;
	}
	if(checkDraw()) {
		std::cout << "We said unbeatable, not always winning." << std::endl;
	}
	delete bot;
}

void Board::aiMove() {
	int move = bot->alphaBeta(this);
	board[move] = aiPlayer;
}

int Board::getTurn() {
	return turn;
}


void Board::placeChar(int n, char c) {
	board[n] = c;
}