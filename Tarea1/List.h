//
// Created by huevitoentorta on 01/03/23.
//
#include <iostream>
using namespace std;
#ifndef TAREA1_LIST_H
#define TAREA1_LIST_H
#include "Node.h"
//ysi incluyo solo gCOlector que luego va a caerle e incluir el node, hagamos la prueba.


class List {
private:
    //aca deberia de tener una instancia de garbage colector
    Node *head;
    Node *current;
    int size;
public:
    List(){
        size = 0;
    }
    void insertFirst(int data){
        if(size != 0){ //creo que aca le estoy diciendo que
            //el valor del pointer ahora sea un nuevo espacio en memoria
            Node *newnode = new(data) Node; //no se si este node
            //vacio esta creando espacio en memoria, en la buena teoria no.
            newnode->setNext(head);
            head = newnode;
            size++;
        }
        else{
            this->head =new(data) Node;
            size++;
        }
    }
    void printList(){
        Node *currente = head;
        for(int i=0;i<size;i++){
            cout<< "el numero es:"<< currente->getData()<<endl;
            currente=currente->getNext();
        }
    }
    Node *gethead(){
        return this->head;
    }
    void deleteFirst(){
        current = head;
        head = head->getNext();
        cout<<"se va a reciclar:"<<current<<endl;
        delete current; //deberia de sobrecargarse
        cout<<"se pudo pasar el delete de la lista"<<endl;
        size--;
    }
    //falta hacer un  metodo delete
};


#endif //TAREA1_LIST_H
