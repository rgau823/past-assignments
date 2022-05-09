/*
CPSC 3750 Rocky Au
Class to represent AI player for TicTacToe
April 1, 2022
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

 	int alphaBeta(Board* game);

 	std::pair<int, int> maxSearch(Board* game, int t, int a, int b);

 	std::pair<int, int> minSearch(Board* game, int t, int a, int b);

 	int score(int depth, Board* game);
};

#endif