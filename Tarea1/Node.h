//
// Created by huevitoentorta on 01/03/23.
//
#include <iostream>
#ifndef TAREA1_NODE_H
#define TAREA1_NODE_H
#include "Gcollector.h"
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
        /**creo que retorna el puntero dereferenciado.*/
    }
    void setNext(Node *ptr){
        this->nextptr = ptr;
        /**creo que esto hace un shallow copy*/
    }
    int getData(){
        return this->number;
    }
    void setData(int data){
        this->number = data;

    }
    void* operator new(size_t size , int data){

        if(Gcollector::getInstance()->getSize()!= 0){
            cout<<"se recicla la memoria"<<endl;
            Node *p =static_cast<Node*>(Gcollector::getInstance()->recoverP());
            cout<<"se reciclo el puntero en memoria:"<<p<<endl;
            p->setData(data);
            return p;
        }
        else{
            cout<<"se crea un nuevo espacio en memoria"<<endl;
            return ::new Node(data); /**NEW GLOBAL */

        }
    }void operator delete(void *p ){
        /**castea el pointer a borrar de tipo void a nodo para que ingrese al gcolector*/
        cout<<"se va a añadir basura"<<endl;
        Gcollector::getInstance()->addTrash(p);
        cout<<"se añadio basura al garbage colector"<<endl;

    }
};


#endif //TAREA1_NODE_H
