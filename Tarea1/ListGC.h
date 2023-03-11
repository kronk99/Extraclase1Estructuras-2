//
// Created by huevitoentorta on 05/03/23.
#include <iostream>
#ifndef TAREA1_LISTGC_H
#define TAREA1_LISTGC_H
#include "NodeGC.h"
/**clase lista que es el almacen de memoria de garbage collector como tal , necesita de nodeGC que es su propio
 * tipo de nodo para esta lista, como dato adicional en algunos retornos de funciones , se debe castear a tipo node*/
class ListGC {
private:
    /**aca deberia de tener una instancia de garbage colector*/
    NodeGC *head;
    NodeGC *current;
    int size;
public:
    ListGC(){ //constructor
        size = 0;
    }
    void insertFirst(void* data){ /**ACA inserta al inicio de NodeGC*/
        if(size != 0){ //si la lista ya tiene algo inserte de esta manera
            NodeGC *newnode = new NodeGC(data);
            newnode->setNext(head);
            head = newnode;
            size++;
        }
        else{/**si es el primer elemento , asignele el head el nuevonodo*/
            this->head = new NodeGC(data);
            size++;
        }
    }
    void printList(){ /**imprime la lista(metodo de prueba, actualmente no utilizado y posiblemente erroneo)*/
        NodeGC *currente = head;
        for(int i=0;i<size;i++){
            /**el static cast convierte el getdata (retorna un void) lo castea a nodo y luego le vuelve a pedir la data(numero)*/
            currente=currente->getNext();
        }
    }
    NodeGC* gethead(){ //retorna un nodoGC
        return this->head; //este no borra el nodo.
    }
    void *getFirst(){
        /**retorna la data del primer elemento de la lista(es decir retorna la data del nodoGC de la lista)*/
        void *ptoReturn=static_cast<void *>(this->head->getData());
        deleteFirst(); //deberia de borrar el nodo de tipo GC
        return ptoReturn; //creo que esto causara problemas
    }
    void deleteFirst(){/**elimina el primer elemento de la lista , le cambia el head a como es necesario*/
        if(size != 0){
            current = head;
            head = head->getNext();
            delete(current);
            cout<<"borrado exitoso"<<endl;
            size--;
        }
        else{
            cout<<"no hay nodos disponibles para retornar."<<endl;

        }
    }
    int getSize(){ /**retorna el tamaño actual de la lista*/
        return this->size;
    }
};
#endif //TAREA1_LISTGC_H
