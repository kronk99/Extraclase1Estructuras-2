//
// Created by huevitoentorta on 05/03/23.
//codigo del nodo de garbage collector que va a almacenar punteros de tipo node.h ,fue necesario castearlo a
//void para evitar errores en el include en node.H
#ifndef TAREA1_NODEGC_H
#define TAREA1_NODEGC_H


class NodeGC {
private:
    NodeGC *head;
    NodeGC *current;
    int size;
public:
private:
    void *data; //quiza esto deba retornar un puntero de un puntero
    NodeGC *nextptr= nullptr;
public:
    NodeGC(void* data){//constructor de nodo
        this->data= data;
    }
    NodeGC *getNext(){//retorna el nodo siguiente
        return this->nextptr;

    }
    void setNext(NodeGC *ptr){
        this->nextptr = ptr;
        //asigna el nodo siguiente
    }
    void* getData(){ //retorna la data , para otros metodos debera de ser casteado a node
        return this->data;
    }
};


#endif //TAREA1_NODEGC_H
