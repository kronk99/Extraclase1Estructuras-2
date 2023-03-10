//
// Created by huevitoentorta on 04/03/23.
//
//la idea que tenia es decir Pointer* = tal dato, asi dereferencio el pointer
//en memoria y ese dato en memoria estaria cambiando
//lo que no se es si el espacio en memoria se debe reutilizar o si simplemente
//debo darle delete y lo que se guarda es el pointer que ahora apunta a nullo.
#include <iostream>

#ifndef TAREA1_GCOLECTOR_H
#define TAREA1_GCOLECTOR_H
#include "ListGC.h"
template <class T>


class Gcolector {
private:
    ListGC<T> *lista;
    int size;
public:
    Gcolector(){
        size = 0;
        lista = new ListGC<T>();
    }
    void addTrash(T *pointer){
        lista->insertFirst(pointer);
        size++;
    }
    T* getData(){ //devuelve un pointer que apunta a un espacio en memoria
        //de un nuevo nodo de tipo GC , tengo que darle GetData para obtener un Nodo de tipo Node
        cout<<"no error"<<endl;
        return lista->gethead()->getData();
    }
    //creo que este return node puede causar problemas puesto que
    //no estoy incluyendo Node.h en la clase.
    T* recoverP(int data){
            T *ptoReturn = lista->getFirst();
            cout<<"el dato en memoria recuperado para reciclar es:"<<ptoReturn->getData();
            ptoReturn->setData(data);
            cout<<"la nueva data del espacio en memoria recilado es:"<<ptoReturn->getData();
            return ptoReturn;
            size--;
        //este metodo retorna el pointer generado en el garbage collector
        //debe elimnar el puntero de la lista, utilizando un delete normal
    }
    int getSize(){
        return lista->getSize();
    }

};


#endif //TAREA1_GCOLECTOR_H
