/*
Rocky Au
Class to represent nodes in the search algorithm
February 4, 2022
*/

#ifndef NODE_H
#define NODE_H

#include <vector>

class Node {
 private:
    Node* parent;
    int CM;
    char side;
    bool explored = false;
    std::vector<Node*> children;


 public:

    Node();

    /*
    Constructor for node class
    */
    Node(int n, Node* p, char s, bool e);

   /*
   Adds the Child to the current node
    */
    void addChild(Node *n);

    /*
   Returns a pointer to the node's parent
    */
    Node* getParent();

    /*
    Gets the numerical representation of the cannibals and missionaries
    */
    int getCM();

    /*
   Returns boolean of if the node has been explored
    */
    bool getExplored();

    /*
   Returns what side the boat is on
    */
    char getSide();


    /*
   Returns a reference ot the vector the node's children
    */
    std::vector<Node*>& getChildren();


    /*
   Sets number of cannibals and missionaries
    */
    void setCM(int i);


    /*
   Sets what side the boat is on
    */
    void setSide(char a);


    /*
   Sets the parent of the node
    */
    void setParent(Node *n);


    /*
   Sets whether the node has been explored
    */
    void setExplored(bool b);


};

#endif // NODE_H