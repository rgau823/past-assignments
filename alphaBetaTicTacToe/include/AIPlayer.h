/*
Rocky Au
Class to represent AI player for TicTacToe
Last updated: May 9, 2022
*/


#ifndef AIPLAYER_H
#define AIPLAYER_H

#include <vector>
#include <utility>
#include "Board.h"

class Board;

class AIPlayer {
 private:
 	
 public:
 	AIPlayer();

    /*
    The function that will start the search. It returns the action for the AI player to take
    */
 	int alphaBeta(Board* game);

    /*
    The function for the max player search
    */
 	std::pair<int, int> maxSearch(Board* game, int t, int a, int b);

    /*
    The function for the min player search
    */
 	std::pair<int, int> minSearch(Board* game, int t, int a, int b);

    /*
    The function to calculate the score for a board. This helps the AI player prune which move to do
    */
 	int score(int depth, Board* game);
};

#endif