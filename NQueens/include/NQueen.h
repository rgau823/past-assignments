/*
Rocky Au
Header file for the NQueens problem
*/

#ifndef NQUEEN_H
#define NQUEEN_H

#include <vector>

class NQueen {
    private:
	 int n; //Number of queens to solve for

	 std::vector<std::vector<int>>board; //2D array representation for board
	 
	 std::vector<int> soln; //Queens actually only need to be placed in a column

	public:

	 NQueen();

	 /*
	Starting function for NQueens problem
	 */
	 NQueen(int c);

	 /*
	Checks if queen can be placed in certain position
	 */
	 bool legalPlacement(int i, int c);
	 /*
	One of the legal placement checkers
	 */
	 bool sameRow(int i, int c);

	 /*
	One of the legal placement checkers
	 */
	 bool sameDiagonal(int i, int c);

	 /*
	Starting function
	 */
	 bool backtrack(int c);

	 /*
	Board to visualize what you can print it as
	 */
	 void printBoard();
};

#endif // NQUEEN_H