#include <iostream>
#include "List.h"
int main() {
    List *lista = new List();
    lista->insertFirst(5);//inserta el numero 5
    lista->insertFirst(6);
    lista->insertFirst(7);
    lista->printList();//imprime la lista
    lista->deleteFirst();//borra el primer elemento de la lista
    cout<<Gcollector::getInstance()->getSize()<<endl; //imprime el tamaño de la lista de Garbagecollecotr
    lista->insertFirst(8);//inserta el 8
    lista->printList();//imprime
    int a = 0; //valor de prueba para ver si el print funciona bien
    cout<<"el numero es"<<a<<endl;
    return 0;
}
//logica del codigo, debo de insertar valores, puedo probar si el puntero se reutiliza haciendo los prints mostrados
//cuando inserta , crea una instancia unica (singleton) del garbage collector, y es usada a medida que se hacen
//deletes o new`s
//CODE MADE BY LUIS GONZALEZ & PABLO SANCHEZ

