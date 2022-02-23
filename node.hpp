#ifndef NODEHPP
#define NODEHPP
#include <string>
using std::string;

class node{
        node* myLeft;
        node* myRight;
        string myName;

    public:
        node();

        node* getRight();
        void setRight(node*);
        node* getLeft();
        void setLeft(node*);
        string getName();
        void setName(string);
};
#endif
