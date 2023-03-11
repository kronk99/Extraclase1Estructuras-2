//
// Created by huevitoentorta on 01/03/23.
//
#include <iostream>
using namespace std;
#ifndef TAREA1_LIST_H
#define TAREA1_LIST_H
#include "Node.h"
/**clase lista, funciona como una lista normal con getters y setters,que le introduce a node para interactuar
 * con la clase node y por consiguiente la memoria*/
class List {
private:
    /**aca deberia de tener una instancia de garbage colector*/
    Node *head;
    Node *current;
    int size;
public:
    List(){
        size = 0;
    }/**metodo que inserta al inicio*/
    void insertFirst(int data){
        if(size != 0){ /**si el tamaño de la lista es diferente de 0*/
            Node *newnode = new(data) Node; /**cree un nuevo nodo, sobrecargando la operacion new*/
            newnode->setNext(head); //el nodo siguiente es el head
            head = newnode;//cambia el head
            size++;
        }
        else{ /**si no, cree un nuevo nodo y asigneselo al puntero head*/
            this->head =new(data) Node;
            size++;
        }
    }
    void printList(){ /**metodo que recorre la lista y la imprime*/
        Node *currente = head;
        for(int i=0;i<size;i++){
            cout<< "el numero es:"<< currente->getData()<<endl;
            currente=currente->getNext();
        }
    }
    Node *gethead(){
        return this->head;
    }
    /**metodo que elimina el primer elemento de la lista y sobrecarga el metodo delete*/
    void deleteFirst(){
        current = head;
        head = head->getNext();
        cout<<"se va a reciclar:"<<current<<endl;
        delete current; //deberia de sobrecargarse
        cout<<"se pudo pasar el delete de la lista"<<endl;
        size--;
    }
};


#endif //TAREA1_LIST_H
