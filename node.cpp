#include "node.hpp"

node::node(){
}

string node::getName(){
    return this->myName;
}

void node::setName(string x){
    this->myName = x;
}

node* node::getRight(){
    return this->myRight;
}

void node::setRight(node *x){
    this->myRight = x;
}

node* node::getLeft(){
    return this->myLeft;
}

void node::setLeft(node *x){
    this->myLeft = x;
}
