//
// Created by huevitoentorta on 05/03/23.
//algo extraño en el codigo es que no puedo sobrecargar el metodo new y delete
//para esta clase, para este codigo no hay inconveniente, pero se ha de realizar,
//la consulta de por que no puedo hacerlo aca.
#ifndef TAREA1_NODEGC_H
#define TAREA1_NODEGC_H
template <class T>
class NodeGC {
private:
    //aca deberia de tener una instancia de garbage colector
    NodeGC *head;
    NodeGC *current;
    int size;
public:
private:
    T *data; //quiza esto deba retornar un puntero de un puntero
    NodeGC *nextptr= nullptr;
public:
    NodeGC(T* data){
        this->data= data;
    }
    NodeGC *getNext(){
        return this->nextptr;
        //creo que retorna el puntero dereferenciado.
    }
    void setNext(NodeGC *ptr){
        this->nextptr = ptr;
        //creo que esto hace un shallow copy
    }
    T* getData(){
        return this->data;
    }
};


#endif //TAREA1_NODEGC_H
