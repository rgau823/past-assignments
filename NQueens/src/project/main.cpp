#include "NQueen.h"
#include <iostream>

int main() {
	int input = 0;
	while (input < 4 || input > 100) {
		std::cout << "Please enter n-queens (4-8): (or perhaps up to 3 if you have time)" << std::endl;
		std:: cin >> input;
	}
	NQueen* nqueen = new NQueen(input);
	nqueen->printBoard();
	delete nqueen;
	return 0;

}