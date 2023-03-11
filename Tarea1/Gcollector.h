//
// Created by huevitoentorta on 10/03/23.
//

#ifndef TAREA1_GCOLLECTOR_H
#define TAREA1_GCOLLECTOR_H

#include <iostream>
using namespace std;
#include "ListGC.h"

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
