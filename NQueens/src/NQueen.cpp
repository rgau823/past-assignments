#include "NQueen.h"
#include <vector>
#include <string>
#include <iostream>

NQueen::NQueen(int n) {
	this->n = n;
	board.resize(n, std::vector<int>(n, 0));
	backtrack(0);
}

bool NQueen::backtrack(int c) {
	if (c>=n) return true;
	for (int i = 0; i < n; ++i) {
		if(legalPlacement(i, c)) {
			board[i][c] = 1;
			int d = c + 1;
			if(backtrack(d)) {
				return true;
			}
			board[i][c] = 0;
		}

	}
	return false;
}

bool NQueen::legalPlacement(int i, int c) {
	if(sameRow(i, c)) return false;
	if(sameDiagonal(i, c)) return false;
	return true;
}

bool NQueen::sameRow(int i, int c) {
	for (int j = c; j >= 0; j--) {
		if(board[i][j]) return true;
	}
	return false;
}

bool NQueen::sameDiagonal(int i, int c) {
	for(int r = 1; r <= c; r++) {
		if((i-r >= 0) && (c-r >=0)) {
			if (board[i-r][c-r]) return true;
		}
		if((i+r <n) && (c-r >= 0)) {
			if (board[i+r][c-r]) return true;
		}
	}
	return false;

}

void NQueen::printBoard() {
	for(int i = 0; i < n*2 + 1; i++) {
		std::cout << "-" << std::flush;
	}
	std::cout << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << "|" << std::flush;
		for (int j = 0; j < n; j++) {
			if(board[i][j]) {
				std::cout << "Q" << std::flush;
			} else {
				std::cout << " " << std::flush;
			}
			std::cout<< "|" << std::flush;
		
}		std::cout << std::endl;
		for(int i = 0; i < n*2 + 1; i++) {
			std::cout << "-" << std::flush;
		}
		std::cout << std::endl;
	}
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			if(board[i][j]) {
				soln.push_back(i);
			}
		}
	}
	std::cout << "Solution can be found by adding Q to the following row from each column left to right:" << std::endl;
	for (int i = 0; i < soln.size(); i++) {
		std::cout << soln[i] << " " << std::flush;
	}
}