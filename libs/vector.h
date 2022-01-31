//
// Created by ну я on 31.01.2022.
//

#ifndef LABA5BVECTORS_VECTOR_H
#define LABA5BVECTORS_VECTOR_H
typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

//возвращает структуру-дескриптор вектор из n значений.
vector createVector(size_t n);

#endif //LABA5BVECTORS_VECTOR_H
