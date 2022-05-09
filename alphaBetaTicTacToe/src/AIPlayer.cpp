/*
Rocky Au
Source file to represent AI player for TicTacToe
Last updated: May 9, 2022
*/

#include <iostream>
#include <algorithm>
#include "AIPlayer.h"
#include "Board.h"


AIPlayer::AIPlayer(){}

int AIPlayer::score(int t, Board* game) {
	if (game->checkDraw()) {
	//A draw is a neutral score
		return 2; 
	}
	int winP = 0;
	if(game->checkEnd()) {
		if (game->checkWinner('X'))	{
			winP = -1;
		}
		if (game->checkWinner('O')) {
			winP = 1;
		}
	//Score based on how many squares are left. A faster victory is a higher score.
		return winP * ((10 - t) + 1); 
	}
	return 0;
}

int AIPlayer::alphaBeta(Board* game) {
	//Game gets initialized with alpha and beta values. Pair is the actual square where player makes move, and score
	int currDepth = game->getTurn();
	int alphaInit = -10000;
	int betaInit = 10000;
	std::pair<int, int> move = maxSearch(game, currDepth, alphaInit, betaInit);
	return move.second;
}

std::pair<int, int> AIPlayer::maxSearch(Board* game, int t, int a, int b) {
	int depth = t + 1; 
	int alpha = a;
	int beta = b;
	int value = -10000;
	int move = -1;
	char max = 'O';
	if (game->checkEnd()) {
		return std::make_pair(score(depth, game), move);
	}
	for (int i = 0; i < 9; i++) {
		if(game->validMove(i)) {
			game->placeChar(i, max);
			std::pair<int, int> newV = minSearch(game, depth, alpha, beta);
			game->placeChar(i, ' ');
			if (newV.first > value) {
				value = newV.first;
				move = i;
				alpha = std::max(alpha, value);
			}
			if (value >= beta) {
				return std::make_pair(value, move);
			} 
			
		} else {
			continue;
		}
	}
	return std::make_pair(value, move);

}

std::pair<int, int> AIPlayer::minSearch(Board* game, int t, int a, int b) {
	
	int depth = t + 1;
	int alpha = a;
	int beta = b;
	int value = 10000;
	int move = -1;
	char min = 'X';
	if (game->checkEnd()) {
		return std::make_pair(score(depth, game), move);
	}
	for (int i = 0; i < 9; i++) {
		if(game->validMove(i)) {
			game->placeChar(i, min);
			std::pair<int, int> newV = maxSearch(game, depth, alpha, beta);
			game->placeChar(i, ' ');
			if (newV.first < value) {
				value = newV.first;
				move = i;
				beta = std::min(beta, value);
			}
			if (value <= alpha) {
				return std::make_pair(value, move);
			}
		} else {
			continue;
		}
	}
	return std::make_pair(value, move);
}