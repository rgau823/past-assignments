#include "Board.h"
#include "AIPlayer.h"

int main() {
	Board* b = new Board();
	b->play();
	delete b;
	return 0;
}