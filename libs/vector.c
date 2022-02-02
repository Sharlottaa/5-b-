#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "vector.h"

vector createVector(size_t n) {
    int *a = (int *) malloc(sizeof(int) * n);
    if (NULL == a) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
    return (vector) {a, 0, n};
}

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

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->size);
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void append(int *a, size_t *n, const int value) {
    a[*n] = value;
    (*n)++;
}

void pushBack(vector *v, int x) {
    if (v->capacity == 0) {
        reserve(v, 1);
    } else if (v->size == v->capacity) {
        reserve(v, v->capacity * 2);
    }
    append(v->data, &v->size, x);
}

void popBack(vector *v) {
    if (isEmpty(&v) == 1) {
        fprintf(stderr, "The vector is empty, we upload the execution with exit... 1");
        exit(1);
    } else {
        (v->size)--;
    }
}

int *atVector(vector *v, size_t index) {
    if (index > v->capacity) {
        fprintf(stderr, "IndexError: a[index] is not exists\"");
        exit(1);
    } else {
        int *ip = &(v->data[index]);
        return ip;
    }
}

int *back(vector *v) {
    return &(atVector(v, v->size - 1));
}

int *front(vector *v) {
    return &(atVector(v, 0));
}







