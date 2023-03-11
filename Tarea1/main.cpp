#include <iostream>
#include "List.h"
int main() {
    List *lista = new List();
    lista->insertFirst(5);
    lista->insertFirst(6);
    lista->insertFirst(7);
    lista->printList();
    lista->deleteFirst();
    cout<<Gcollector::getInstance()->getSize()<<endl;
    lista->insertFirst(8);
    lista->printList();
    int a = 0;
    cout<<"el numero es"<<a<<endl;
    return 0;
}

