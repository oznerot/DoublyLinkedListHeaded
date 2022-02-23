//Bibliotecas
#include <iostream>
#include "listadupla.hpp"

//Protótipos
    void printLista(Lista *);
    void interface(Lista *, int);
    void comparaLista(Lista *, Lista *);

//Programa Principal
int main(){
    Lista *L1 = new Lista();
    Lista *L2 = new Lista();
    string name;
    int choice = -1;

    std::cout << "PRIMEIRA LISTA" << std::endl;
    interface(L1, choice);
    
    std::cout << "SEGUNDA LISTA" << std::endl;
    interface(L2, choice);


    while(choice != 1 && choice != 2 ){
        std::cout << "PRINTAR LISTAS?" << std::endl;
        std::cout << "1. Sim" << std::endl << "2. Nao" << std::endl;
        std::cin >> choice;
    
        if(choice == 1){
            std::cout << "PRIMEIRA LISTA" << std::endl;
            printLista(L1);

            std::cout << "SEGUNDA LISTA" << std::endl;
            printLista(L2);
        }
        else if(choice != 2){
            std::cout << "Escolha invalida." << std::endl;
        }      
    }
    choice = 0;
    while(choice != 1 && choice != 2){
        std::cout << "COMPARAR LISTAS?" << std::endl;
        std::cout << "1. Sim" << std::endl << "2. Nao" << std::endl;
        std::cin >> choice;

        if(choice == 1){
            comparaLista(L1, L2);
        }
        else if(choice != 2)
            std::cout << "Escolha invalida." << std::endl;
    }

    return 0;
}

/*Interface de criação das listas*/
void interface(Lista *L, int choice){
    string name;

    while(choice!=0){
        std::cout << "1. Adicionar nome na lista." << std::endl;
        std::cout << "2. Remover nome da lista." << std::endl;
        std::cout << "0. Finalizar lista." << std::endl;
        std::cin >> choice;

        switch(choice){
            case 1:
                std::cout << "Nome: ";
                std::cin >> name;
                if(!L->insertNode(name))
                    std::cout << "Nome ja presente na lista." << std::endl;
                break;

            case 2:
                std::cout << "Nome: ";
                std::cin >> name;
                if(!L->removeNode(name))
                    std::cout << "Nome nao encontrando." << std::endl;
                break;
            case 0:
                break;

            default:
                std::cout << "Escolha invalida, tente novamente" << std::endl;
        }
    }
}

/*Função para impressão da Lista*/
void printLista(Lista *L){
    bool isTrue = true;
    if(!L->isVazia()){
        while(isTrue == true){
            std::cout << "|" << L->getCurrentName();

            isTrue = L->getNextNode();
        }
        std::cout << "|" << std::endl;
    }
    else
        std::cout << "Lista vazia!" << std::endl;

}

/*Função para comparar duas listas*/
void comparaLista(Lista *L1, Lista *L2){
    bool isEqual = true;
    bool firstListEnded = true;
    bool secondListEnded = true;
    if(L1->isVazia() && L2->isVazia()){
        std::cout << "Ambas as listas estao vazias." << std::endl;
    }

    else if(L1->isVazia() || L2->isVazia()){
        std::cout << "Uma das filas esta vazia." << std::endl;
    }

    else{
        while(firstListEnded || secondListEnded){
            if((L1->getCurrentName()) != (L2->getCurrentName())){
                isEqual = false;

            }
            if(firstListEnded)
                firstListEnded = L1->getNextNode();

            if(secondListEnded)
                secondListEnded = L2->getNextNode();
        }

        if(isEqual)
            std::cout << "Ambas as listas sao iguais." << std::endl;
        else
            std::cout << "As listas sao diferentes" << std::endl;
    }

}
