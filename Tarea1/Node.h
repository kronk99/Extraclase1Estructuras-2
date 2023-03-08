//
// Created by huevitoentorta on 01/03/23.
//
#include <iostream>
#ifndef TAREA1_NODE_H
#define TAREA1_NODE_H
#include "Gcolector.h"
class Node {
private:
    int number;
    Node *nextptr= nullptr;
public:
    Node(int data){
        this->number = data;
    }
    Node(){

    }
    Node *getNext(){
        return this->nextptr;
        //creo que retorna el puntero dereferenciado.
    }
    void setNext(Node *ptr){
        this->nextptr = ptr;
        //creo que esto hace un shallow copy
    }
    int getData(){
        return this->number;
    }
    void setData(int data){
        this->number = data;
    }
    //prueba experimental con el int data a ver si asi puedo dereferenciar
    //el datatype que contiene y cambiarselo
    void* operator new(size_t size ,Gcolector<Node> *collector, int data){
        //Se decide que el garbage collector se pase como argumento, por que si
        //lo almacena en una variable es memoria consuminda , por lo que al
        //almacenarlo en la funcion en teoria estaria en el stack, y cuando
        //esta funcion termine , el stack se autogestiona.
        Gcolector<Node> *colector = collector;
        if(colector->getSize() != 0){
            cout<<"se recicla la memoria"<<endl;
            void *p =colector->recoverP(data);
            return p;

        }
        else{
            cout<<"se crea un nuevo espacio en memoria"<<endl;
            void *p = ::new Node(data);
            return p;
        }
    }void operator delete(void *){
        colector->addTrash(pointer);
        cout<<"se añadio basura al garbage colector"<<endl;

    }

};


#endif //TAREA1_NODE_H
