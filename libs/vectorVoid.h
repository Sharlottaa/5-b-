//
// Created by ну я on 03.02.2022.
//

#ifndef LABA5BVECTORS_VECTORVOID_H
#define LABA5BVECTORS_VECTORVOID_H

#include <limits.h>

typedef struct vectorVoid {
    void *data; // указатель на нулевой элемент вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
    size_t baseTypeSize; // размер базового типа:
} vectorVoid;



#endif //LABA5BVECTORS_VECTORVOID_H
