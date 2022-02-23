#ifndef LISTAHPP
#define LISTAHPP
#include "node.hpp"

class Lista{
        node* m_head;
        node* currentNodePtr;

    public:
        Lista();
        bool isCheia();
        bool isVazia();
        bool insertNode(string);
        bool removeNode(string);
        string getCurrentName();
        bool getNextNode();

};

#endif
