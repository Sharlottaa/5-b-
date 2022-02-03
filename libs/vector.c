#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "vector.h"
#include <assert.h>


//возвращает структуру-дескриптор вектор из n значений.
vector createVector(size_t n) {
    int *a = (int *) malloc(sizeof(int) * n);
    if (NULL == a) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
    return (vector) {a, 0, n};
}

//изменяет количество памяти, выделенное под хранение элементов вектора
void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
    } else if (newCapacity < v->size) {
        v->size = newCapacity;
    } else {
        int *a = realloc(v->data, sizeof(int) * newCapacity);
        if (NULL == a) {
            fprintf(stderr, "bad alloc ");
            exit(1);
        }
        v->capacity = newCapacity;
    }
}

//удаляет элементы из контейнера, но не освобождает выделенную память.
void clear(vector *v) {
    v->size = 0;
}

// освобождает память, выделенную под неиспользуемые элементы
void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

//освобождает память, выделенную вектору
void deleteVector(vector *v) {
    free(v->size);
}

//возвращает значение ’истина’, если вектор является пустым, иначе - ’ложь’
bool isEmpty(vector *v) {
    return v->size == 0;
}

//возвращает значение ’истина’, если вектор является полными, иначе - ’ложь’
bool isFull(vector *v) {
    return v->size == v->capacity;
}

//возвращает i-ый элемент вектора v
int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void append(int *a, size_t *n, const int value) {
    a[*n] = value;
    (*n)++;
}

//добавляет элемент x в конец вектора v.
void pushBack(vector *v, int x) {
    if (v->capacity == 0) {
        reserve(v, 1);
    } else if (v->size == v->capacity) {
        reserve(v, v->capacity * 2);
    }
    append(v->data, &v->size, x);
}

//удаляет последний элемент из вектора
void popBack(vector *v) {
    if (isEmpty(&v) == 1) {
        fprintf(stderr, "The vector is empty, we upload the execution with exit... 1");
        exit(1);
    } else {
        (v->size)--;
    }
}

//возвращает указатель на index-ый элемент вектора
int *atVector(vector *v, size_t index) {
    assert(v->size > 0);
    if (index > v->capacity) {
        fprintf(stderr, "IndexError: a[index] is not exists\"");
        exit(1);
    } else {
        int *ip = &(v->data[index]);
        return ip;
    }
}

//возвращает указатель на последний элемент вектора
int *back(vector *v) {
    assert(v->size > 0);
    int *ip = atVector(v, v->size - 1);
    return ip;
}

//возвращает указатель на первый элемент вектора
int *front(vector *v) {
    assert(v->size > 0);
    int *ip = atVector(v, 0);
    return ip;
}







