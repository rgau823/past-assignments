/*
Rocky Au
The CPP file for the graph class
February 4, 2022
*/

#include "Graph.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

Graph::~Graph(){
	for (auto n : history) {
		delete n;
	}
	history.clear();
}

void Graph::search() {
	//defines the search algorithm (BFS implementation)
	//while the current node is not the desired state
	Node* curr = breadth.front();

	while(!(found)) {
		if (curr->getExplored()) //Checks if a node has already been explored. If so, goes to next
			continue;
		if (curr->getCM() == 0) { 	//First check if the current node is the goal node
			setFound(true); //Exits loop to print answer if found
			continue;
		} else {
			/*Algorithm is as follows. Sets current node as explored. Adds that nodes children to the Node
			Then that node is added to a history vector. The node's children are added to the queue. We remove
			the current node from the queue.*/
			curr->setExplored(true);
			addChildren(curr);
			addToHistory(curr);
			addChildToQueue(curr);
			delNode(curr);
			curr = breadth.front();
		}
	}
	solution(curr);
}

void Graph::addChildren(Node* curr) {
	//determine which children are legal
	int CM = curr->getCM();
	char side = curr->getSide();
	if(side == 'L') {
		//Possible actions: Send C or M to the goal side
		if (CM >= 10) { //Able to send 1 cannibals
			int i = CM - 10;
			curr->addChild(new Node(i, curr, 'R', false));
		}

		if (CM >= 20) { //Able to send 2 cannibals
			int i = CM - 20;
			curr->addChild(new Node(i, curr, 'R', false));
		}

		if (CM % 10 >= 1) { //Able to send 1 missionary
			int i = CM - 1;
			curr->addChild(new Node(i, curr, 'R', false));
		}

		if (CM%10 >= 2) { //Able to send 2 dictionary
			int i = CM - 2;
			curr->addChild(new Node(i, curr, 'R', false));
		}

		if ((CM/10 >= 2) && (CM%10 >=2)) { //Able to send 1 missionary and 1 cannibal
			int i = CM - 11;
			curr->addChild(new Node(i, curr, 'R', false));
		}

	} else if (side ==  'R') {
		if (CM < 30) { //Able to send 1 cannibal back
			int i = CM + 10;
			curr->addChild(new Node(i, curr, 'L', false));
		}

		if (CM < 20) { //Able to send 2 cannibals back
			int i = CM + 20;
			curr->addChild(new Node(i, curr, 'L', false));
		}

		if (CM%10 <= 1) { //Able to send 2 missionaries back
			int i = CM + 2;
			curr->addChild(new Node(i, curr, 'L', false));
		}

		if (CM%10 <= 2) { //Able to send 1 missionary back
			int i = CM + 1;
			curr->addChild(new Node(i, curr, 'L', false));
		}

		if ((CM/10<=2)&&(CM%10<=2)) { //Able to send back 1 missionary and 1 cannibal
			int i = CM + 11;
			curr->addChild(new Node(i, curr, 'L', false));
		}
	}
	checkLegal(curr);
}

void Graph::addToQueue(Node* n) {
	//Function to add children to queue
	breadth.push(n);

}

void Graph::addChildToQueue(Node* n) {
	for (auto m : n->getChildren()) {
		if(!(m->getExplored())) {
			//Adds children to queue if not explored yet
			addToQueue(m);
		}

	}
}

void Graph::addToHistory(Node* n) {
	history.push_back(n);
}

void Graph::checkLegal(Node* curr) {
	for (std::vector<Node*>::iterator it = curr->getChildren().begin(); it!= curr->getChildren().end(); it++) {
		int state = (*it)->getCM();
		char a = (*it)->getSide();
		//Checks if it is in an illegal state (more C than M on any side)
		if(state == 12 || state == 21 || state == 31 || state == 32 || state == 2) {
			(*it)->setExplored(true);
		}
		for (auto m : history) {
			int histCM = m->getCM();
			char histS = m->getSide();
			if (state == histCM && a == histS) {
				(*it)->setExplored(true);
			}
		}

	}
}

void Graph::delNode(Node* n) {
	breadth.pop();
}

void Graph::solution(Node* n) {
	std::cout << "We begin with 3 cannibals and 3 missionaries." << std::endl;
	std::cout << "10's position represents cannibals, 1's missionaries" << std::endl;
	Node* sol = n;
	while(sol != nullptr) {
		answers.push(sol);
		sol = sol->getParent();
	}
	while(!(answers.empty())) {
		sol = answers.top();
		int prev;
		if (sol->getParent()!= nullptr) {
			prev = sol->getParent()->getCM();
		}
		int lSide = sol->getCM();
		int rSide = 33 - lSide;
		prev = lSide - prev;
		if (lSide < 10) {
			std::cout <<"0" << lSide << "              " << rSide;
		}else if (rSide < 10) {
			std::cout << lSide << "              " << "0" <<rSide;
		} else {
			std::cout<< lSide << "              " <<rSide;
		}
		switch(prev) {
			case -20:
				std::cout << " sent 2 cannibals over (boat on the right)";
				break;
			case 20:
				std::cout << " sent 2 cannibals back (boat on the left)";
				break;
			case -10:
				std::cout << " sent 1 cannibal over (boat on the right)";
				break;
			case 10:
				std::cout << " sent 1 cannibal back (boat on the left)";
				break;
			case -2:
				std::cout << " sent 2 missionaries over (boat on the right)";
				break;
			case 2:
				std::cout << " sent 2 missionaries back (boat on the left)";
				break;
			case -1:
				std::cout << " sent 1 missionary over (boat on the right)";
				break;
			case 1:
				std::cout << " sent 2 missionary back (boat on the left)";
				break;
			case -11:
				std::cout << " sent 1 cannibal and 1 missionary over (boat on the right)";
				break;
			case 11:
				std::cout << " sent 1 missionary and 1 cannibal back (boat on the left)";
				break;
		}
		std::cout << std::endl;
		answers.pop();
	}
	std::cout << "And everyone survived and is happy!" << std::endl;
}

void Graph::setFound(bool f) {
	found = f;
}