//Bibliotecas
#include "listadupla.hpp"

Lista::Lista(){
    m_head = new node();
    currentNodePtr = new node();
    m_head->setLeft(m_head);
    m_head->setRight(m_head);
}

bool Lista::isVazia(){
    return m_head == m_head->getRight();
}

bool Lista::insertNode(string x){   
    bool isSuccessful = false;
    bool theyAreEqual = false;
    node* auxiliarPointer = new node();
    auxiliarPointer->setName(x);

    //Caso a lista esteja vazia
    if(this->isVazia()){
        auxiliarPointer->setRight(m_head);
        auxiliarPointer->setLeft(m_head);
        m_head->setRight(auxiliarPointer);
        m_head->setLeft(auxiliarPointer);
    
        isSuccessful = true;
    }

    else{
        auxiliarPointer->setRight(m_head->getRight());

        while(auxiliarPointer->getRight() != m_head && theyAreEqual == false && isSuccessful == false){

            //Caso string vem primeiro
            if((auxiliarPointer->getName()).compare(auxiliarPointer->getRight()->getName()) < 0){

                auxiliarPointer->setLeft(auxiliarPointer->getRight()->getLeft());
                auxiliarPointer->getRight()->setLeft(auxiliarPointer);
                auxiliarPointer->getLeft()->setRight(auxiliarPointer);


                isSuccessful = true;                  
            }

            //Caso string igual
            else if((auxiliarPointer->getName()).compare(auxiliarPointer->getRight()->getName()) == 0){
                theyAreEqual = true;
            }

            //Caminhar fila
            if (isSuccessful == false)
                auxiliarPointer->setRight(auxiliarPointer->getRight()->getRight());

            
        }
        if(theyAreEqual == false && isSuccessful == false){
            auxiliarPointer->setLeft(m_head->getLeft());

            auxiliarPointer->getLeft()->setRight(auxiliarPointer);
            m_head->setLeft(auxiliarPointer);

            isSuccessful = true;
        }
    }

    currentNodePtr = m_head->getRight();

    return isSuccessful;
}

bool Lista::removeNode(string x){
    bool isSuccessful = false;
    node* auxiliarPointer = new node();
    auxiliarPointer->setName(x);

    if(!this->isVazia()){
        auxiliarPointer->setRight(m_head->getRight());

        while(auxiliarPointer->getRight() != m_head && isSuccessful == false){

            if((auxiliarPointer->getName()).compare(auxiliarPointer->getRight()->getName()) == 0){
                auxiliarPointer->getRight()->getRight()->setLeft(auxiliarPointer->getRight()->getLeft());
                auxiliarPointer->getRight()->getLeft()->setRight(auxiliarPointer->getRight()->getRight());

                isSuccessful = true;
            }


            if(isSuccessful == false)
                auxiliarPointer->setRight(auxiliarPointer->getRight()->getRight());
                

            else
                delete (auxiliarPointer->getRight());
        }
        currentNodePtr = m_head->getRight();
    }
    else{
        currentNodePtr = m_head;
    }

    delete (auxiliarPointer);
    return isSuccessful;
}


string Lista::getCurrentName(){
    return currentNodePtr->getName();
}

/*Função para percorrer a Lista, retorna FALSE se encontrar
o header e TRUE caso não */
bool Lista::getNextNode(){
    bool result = true;

    if(currentNodePtr->getRight() != m_head){
        currentNodePtr = currentNodePtr->getRight();      
    }

    else{
        currentNodePtr = m_head->getRight();      
        result = false;
    }

    return result;
}
