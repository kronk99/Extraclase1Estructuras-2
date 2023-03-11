//
// Created by huevitoentorta on 05/03/23.
//ACA QUEDO EL ERROR A ARREGLAR
#include <iostream>

#ifndef TAREA1_LISTGC_H
#define TAREA1_LISTGC_H
#include "NodeGC.h"

class ListGC {
private:
    //aca deberia de tener una instancia de garbage colector
    NodeGC *head;
    NodeGC *current;
    int size;
public:
    ListGC(){
        size = 0;
    }
    void insertFirst(void* data){ //ACA USAR TEMPLATE
        if(size != 0){
            NodeGC *newnode = new NodeGC(data);
            newnode->setNext(head);
            head = newnode;
            size++;
        }
        else{
            this->head = new NodeGC(data);
            size++;
        }
    }
    void printList(){ //otro condicional.
        NodeGC *currente = head;
        for(int i=0;i<size;i++){
            //el static cast convierte el getdata (retorna un void) lo castea a nodo y luego le vuelve a pedir la data(numero)
            currente=currente->getNext();
        }
    }
    NodeGC* gethead(){ //retorna un nodoGC
        return this->head; //este no borra el nodo.
    }
    void *getFirst(){//aca se debe de colocar un condicional.
        //retorna la data del primer elemento.
        void *ptoReturn=static_cast<void *>(this->head->getData());
        deleteFirst(); //deberia de borrar el nodo de tipo GC
        return ptoReturn; //creo que esto causara problemas
    }
    void deleteFirst(){
        if(size != 0){
            current = head;
            head = head->getNext();
            delete(current);
            cout<<"borrado exitoso"<<endl;
            size--;
        }
        else{
            cout<<"no hay nodos disponibles para retornar."<<endl;
            //linea un poco redundante , puesto que para regresar del garbage collector
            //debe preguntar si tiene algo en el garbage collector (size).
        }
    }
    int getSize(){
        return this->size;
    }
};
#endif //TAREA1_LISTGC_H
