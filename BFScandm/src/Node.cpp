/*
Rocky Au
The cpp file for the Node class
February 4, 2022

*/

#include "Node.h"
#include <vector>
#include <iostream>

Node::Node(int n, Node* p, char s, bool e) {
	CM = n;
	parent = p;
	side = s;
	explored = e;
}

void Node::addChild(Node *n) {
	children.push_back(n);
}

//returns the node's parent
Node* Node::getParent() {
	return parent;
}

//return the number of cannibal's and missionaries
int Node::getCM() {
	return CM;
}

bool Node::getExplored() {
	return explored;
}

char Node::getSide() {
	return side;
}

std::vector<Node*>& Node::getChildren() {
	return children;
}

void Node::setCM(int i) {
	CM = i;
}

void Node::setSide(char a) {
	side = a;
}

void Node::setParent(Node *n) {
	parent =  n;
}

void Node::setExplored(bool b) {
	explored = b;
}

