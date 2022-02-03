//
// Created by ну я on 03.02.2022.
//
#include <stdio.h>
#include <malloc.h>
#include "vectorVoid.h"

//возвращает структуру-дескриптор вектор из n значений.
vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    int *a = (int *) malloc(baseTypeSize * n);
    if (NULL == a) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
    return (vectorVoid) {a, 0, n, baseTypeSize};
}

//изменяет количество памяти, выделенное под хранение элементов вектора
void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
    } else if (newCapacity < v->size) {
        v->size = newCapacity;
    } else {
        int *a = realloc(v->data, v->baseTypeSize * newCapacity);
        if (NULL == a) {
            fprintf(stderr, "bad alloc ");
            exit(1);
        }
        v->capacity = newCapacity;
    }
}

//удаляет элементы из контейнера, но не освобождает выделенную память.
void clearV(vectorVoid *v) {
    v->size = 0;
}

// освобождает память, выделенную под неиспользуемые элементы
void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

//освобождает память, выделенную вектору
void deleteVectorV(vectorVoid *v) {
    free(v->size);
}