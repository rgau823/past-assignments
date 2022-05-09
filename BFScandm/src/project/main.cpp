#include <iostream>
#include "Graph.h"
#include "Node.h"

int main() {
	std::cout << "test" << std::endl;
	int start = 33;
	Node* startState = new Node(33, nullptr, 'L', false);
	Graph* searchGraph = new Graph();
	searchGraph->addToQueue(startState);
	searchGraph->search();
	delete searchGraph;	
	return 0;
}