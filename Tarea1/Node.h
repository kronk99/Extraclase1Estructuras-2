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
    Gcolector<Node> *gcolector; //ocupa 8 bits y al ser obligada a ser declarada static
    static Gcolector<Node> *perro;
    //dura todoo el periodo de vida del programa
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
    /*este metodo se utiliza nuevo del newNode, dado la explicacion de ese metodo
     * por lo tanto , luego de haber hecho el newNode ,debo usar este metodo para insertar
     * el pointer gcolector en la clase nodo (8bits) , para asi poder usar el delete, dado que
     * delete no acepta mas argumentos , si se programa para que los acepte, deja de sobreescribirse y
     * se convierte en un metodo de node como tal.(basicamente en vez de decir Delete prt , se convierte en
     * ptr->delete )*/
    void insertColector(Gcolector<Node> *collectores){
        gcolector = collectores;
        perro = gcolector;
    }
    //prueba experimental con el int data a ver si asi puedo dereferenciar
    //el datatype que contiene y cambiarselo
    void* operator new(size_t size ,Gcolector<Node> *collectores, int data){
        //Se decide que el garbage collector se pase como argumento, por que si
        //lo almacena en una variable es memoria consuminda , por lo que al
        //almacenarlo en la funcion en teoria estaria en el stack, y cuando
        //esta funcion termine , el stack se autogestiona.
        //no puedo decirle atributo gcolector = *collectores por que el nodo todavia no esta creado
        //hasta que se retorne, por lo tanto no hay atributo donde almacenarlo, solo despues del return p.
        if(collectores->getSize() != 0){
            cout<<"se recicla la memoria"<<endl;
            void *p =collectores->recoverP(data);
            return p;

        }
        else{
            cout<<"se crea un nuevo espacio en memoria"<<endl;
            void *p = ::new Node(data);
            return p;
        }
    }void operator delete(void *p ){
        //castea el pointer a borrar de tipo void a nodo para que ingrese al gcolector
        cout<<"se va a añadir basura"<<endl;
        perro->addTrash(static_cast<Node *>(p));
        cout<<"se añadio basura al garbage colector"<<endl;
        free(p);
    }
};


#endif //TAREA1_NODE_H
