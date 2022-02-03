//
// Created by ну я on 03.02.2022.
//
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vectorVoid.h"
#include <string.h>

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

//возвращает значение ’истина’, если вектор является пустым, иначе - ’ложь’
bool isEmptyV(vectorVoid *v){
    return v->size==0;
}

//возвращает значение ’истина’, если вектор является полными, иначе - ’ложь’
bool isFullV(vectorVoid *v){
    return v->size==v->capacity;
}

//записывает по адресу destination index-ый элемент вектора v
void getVectorValueV(vectorVoid *v, size_t index, void *destination){
    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

//записывает на index-ый элемент вектора v значение, расположенное по адресу source
void setVectorValueV(vectorVoid *v, size_t index, void *source){
    char *destination = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

//удаляет последний элемент из вектора
void popBackV(vectorVoid *v){
    if (isEmptyV(&v) == 1) {
        fprintf(stderr, "The vector is empty, we upload the execution with exit... 1");
        exit(1);
    } else {
        (v->size)--;
    }
}


//добавляет элемент x в конец вектора v
void pushBackV(vectorVoid *v, void *source){
    if (v->capacity == 0) {
        reserveV(v, 1);
    } else if (v->size == v->capacity) {
        reserveV(v, v->capacity * 2);
    }
    setVectorValueV(v,v->size,source);
    v->size++;
}
