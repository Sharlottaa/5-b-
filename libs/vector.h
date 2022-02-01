//
// Created by ну я on 31.01.2022.
//
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#ifndef LABA5BVECTORS_VECTOR_H
#define LABA5BVECTORS_VECTOR_H
typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

//возвращает структуру-дескриптор вектор из n значений.
vector createVector(size_t n);

//изменяет количество памяти, выделенное под хранение элементов вектора
void reserve(vector *v, size_t newCapacity);

//удаляет элементы из контейнера, но не освобождает выделенную память.
void clear(vector *v);

// освобождает память, выделенную под неиспользуемые элементы
void shrinkToFit(vector *v);

//освобождает память, выделенную вектору
void deleteVector(vector *v);

//возвращает значение ’истина’, если вектор является пустым, иначе - ’ложь’
bool isEmpty(vector *v);

//возвращает значение ’истина’, если вектор является полными, иначе - ’ложь’
bool isFull(vector *v);

//возвращает i-ый элемент вектора v
int getVectorValue(vector *v, size_t i);
#endif //LABA5BVECTORS_VECTOR_H
