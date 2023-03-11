//
// Created by huevitoentorta on 10/03/23.
//

#ifndef TAREA1_GCOLLECTOR_H
#define TAREA1_GCOLLECTOR_H

#include <iostream>
using namespace std;
#include "ListGC.h"
/*clase que maneja el recolector de basura, tiene de atributos una lista, que va a almacenar punteros
 * de tipo node.h(nodo de la lista)*/
class Gcollector {
private:
    ListGC *lista;
    int size;
    static Gcollector* pointer;
public:
    Gcollector();
    static Gcollector* getInstance();
    void addTrash(void *pointer);
    void* getData();
    void* recoverP();
    int getSize();
};

#endif //TAREA1_GCOLLECTOR_H
