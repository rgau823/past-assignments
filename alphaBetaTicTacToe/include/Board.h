/*
CPSC 3750 Rocky Au
Class to represent states in the search algorithm
April, 2022

Header file for the board class. The class enforces the rules of the game and plays it.
*/


#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <utility>
#include "AIPlayer.h"

class AIPlayer;

class Board {
 private:
 	std::vector<char> board = {' ', ' ', ' ', 
 							   ' ', ' ', ' ',
 							   ' ', ' ', ' '};

 	char player = 'X';
 	char aiPlayer = 'O';
 	int turn;
 	AIPlayer* bot;

 public:

 	Board();
 	/*
 	Outputs the boards current state
 	*/	
 	void displayBoard();

 	/*
	Starts playing the game
 	*/
 	void play();

 	/*
	Check if the game is in a draw state
 	*/
 	bool checkDraw();

 	/*
	Checks if specific player is the winner and game is in an end state
 	*/
 	bool checkEnd(char c);


 	/*
	Checks if game is in end state
 	*/
 	bool checkEnd();


 	/*
	Checks to see if the player's a winner
 	*/
 	bool checkWinner(char c);


 	/*
	The human player's sequence of events when it's their move
 	*/
 	void playerMove();

 	/*
	The AI player's sequence of events when it's their turn
 	*/
 	void aiMove();

 	/*
	Checks if space on grid is empty
 	*/
 	bool validMove(int i);

 	/*
	Returns the board
 	*/
 	std::vector<char> getBoard();

 	/*
	Determins how many turns have occcurred (for depth)
 	*/
 	int getTurn();

 	/*
	Puts X or O where n is.
 	*/
 	void placeChar(int n, char c);

};

#endif