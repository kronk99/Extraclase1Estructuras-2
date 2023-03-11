//
// Created by huevitoentorta on 10/03/23.
//

#include "Gcollector.h"
Gcollector* Gcollector::pointer= nullptr;
//constructor no tiene tipo de dato
Gcollector::Gcollector(){
    size = 0;
    lista = new ListGC();
}
//tipo de dato , clase que pertenece, metodo
Gcollector* Gcollector:: getInstance(){
    if(pointer== nullptr){
        cout<<"el gcolector estaba nulo"<<endl;
        pointer = new Gcollector();
        return pointer;
    }
    else{
        cout<<"ya esta creado el gcolector"<<endl;
        return pointer;
    }
}
void Gcollector:: addTrash(void *pointer){
    lista->insertFirst(pointer);
    size++;
}
void* Gcollector:: getData(){ //devuelve un pointer que apunta a un espacio en memoria
    //de un nuevo nodo de tipo GC , tengo que darle GetData para obtener un Nodo de tipo Node
    cout<<"no error"<<endl;
    return lista->gethead()->getData();
}
void * Gcollector::recoverP(){
    return lista->getFirst();
}
int Gcollector::getSize(){
    return lista->getSize();
}
