//
// Created by huevitoentorta on 05/03/23.
//ACA QUEDO EL ERROR A ARREGLAR
#include <iostream>

#ifndef TAREA1_LISTGC_H
#define TAREA1_LISTGC_H
#include "NodeGC.h"
template <class T>
class ListGC {
private:
    //aca deberia de tener una instancia de garbage colector
    NodeGC<T> *head;
    NodeGC<T> *current;
    int size;
public:
    ListGC(){
        size = 0;
    }
    void insertFirst(T* data){ //ACA USAR TEMPLATE
        if(size != 0){
            NodeGC<T> *newnode = new NodeGC(data);
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
        NodeGC<T> *currente = head;
        for(int i=0;i<size;i++){

            std::cout<<"no error de momento xd" << currente->getData()->getData() <<std::endl;
            currente=currente->getNext();
        }
    }
    NodeGC<T> *gethead(){ //retorna un nodoGC
        return this->head; //este no borra el nodo.
    }
    T *getFirst(){//aca se debe de colocar un condicional.
        //retorna la data del primer elemento.
        T *ptoReturn=this->head->getData();
        deleteFirst(); //deberia de borrar el nodo de tipo GC
        return ptoReturn; //creo que esto causara problemas
    }
    void deleteFirst(){
        if(size != 0){
            /*current ahora apunta a lo que apunta head
             head ahora apunta al siguiente
             por ultimo, se borra a lo que apunta current , que es un espacio
             en memoria que almacena un valor de tipo NodeGC, el puntero de importancia
             que es el pointer del espacio en memoria llamado Node no se pierde
             ya que se regreso inicialmente al usar el metodo getFIrst, ya luego en el programa
             se dereferencia y le cae encima.*/
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
