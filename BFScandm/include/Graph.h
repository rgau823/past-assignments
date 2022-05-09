/*
Rocky Au
Class to represent graph in the search algorithm
February 4, 2022
*/

#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"
#include <queue>
#include <vector>
#include <stack>


class Graph {
 private:
   std::queue<Node*> breadth;
   std::vector<Node* > history;
   std::stack<Node*> answers;
   int goal = 0;
   bool found;

 public:

   virtual ~Graph(); 


   /*
  Starts the search for the goal
   */
   void search();


   /*
  Sets if the goal state is found
   */
   void setFound(bool b);


   /*
  Adds the node's children to the queue
   */
   void addChildToQueue(Node* n);


   /*
  Adds the node to the queue
   */
   void addToQueue(Node* n);

   /*
  Add node to the history
   */
   void addToHistory(Node* n);

   /*
  The call to create the node's children
   */
   void addChildren(Node* n);

   /*
  Test for if the children are legal
   */
   void checkLegal(Node* n);  

   /*
  Removes current node from queue
   */
   void delNode(Node* n);

   /*
  Prints solution when found
   */
   void solution(Node *n);

};

#endif // NODE_H