#include <iostream>
#include "List.h"
#include "ListGC.h"
int main() {
    /*
    std::cout << "Hello, World!" << std::endl;
    Node *nodo = new Node(5);
    Node *nodo2 = new Node(7);
    Node *nodo3 = new Node(8);
    Node *nodo4 = new Node(9);
    nodo->setNext(nodo2);
    nodo2->setNext(nodo3);
    nodo3->setNext(nodo4);
    int a = 0;
    Node *Current = nodo;
    for(a;a<4;a++){
        std::cout<<"el numero es:"<<Current->getData()<<std::endl;
        Current = Current->getNext(); //esto me lo pone nulo al llegar al 3 iteracion
    }
     */
    //primero se debe inicializar el colector y mandarselo a lista.
    List *lista = new List();
    Gcolector<Node> *gcolector = new Gcolector<Node>();
    lista->insertGC(gcolector);

    lista->insertFirst(5);
    lista->insertFirst(8);
    cout<<"el pointer es"<<lista->gethead()<<endl;
    std::cout<<"no error de momento aaa" <<std::endl;
    lista->printList();
    //lista->deleteFirst(); //borra la cabeza de la lista.
    //cout<<"el delete es " << gcolector->getData()<<endl;
    //cout<<"el nuevo head es:"<<lista->gethead()<<endl;

    return 0;
}
