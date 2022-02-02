#include <stdio.h>
#include "libs/vector.h"
#include <stdint.h>
#include "libs/vector.h"
#include <assert.h>


void test_pushBack_emptyVector1() {
    vector v = createVector(0);
    assert(isEmpty(&v) == 1);
    pushBack(&v, 10);
    assert(v.size == 1);
    assert(v.capacity == 1);
    assert(v.data[0] == 10);
}

void test_pushBack_emptyVector2() {
    vector v = createVector(0);
    pushBack(&v, 42);

    assert(v.size == 1);
    assert(v.capacity == 1);
    assert(isEmpty(&v) == 0);
    assert(v.data[0] == 42);
}

void test_pushBack_emptyVector3() {
    vector v = createVector(0);
    assert(isEmpty(&v) == 1);
    pushBack(&v, 10);
    pushBack(&v, 3);
    pushBack(&v, 12);
    popBack(&v);
    popBack(&v);

    assert(v.size == 1);
    assert(v.capacity == 4);
    assert(v.data[0] == 10);
}

void test_pushBack_emptyVector4() {
    vector v = createVector(0);
    assert(isEmpty(&v) == 1);
    pushBack(&v, 10);
    popBack(&v);

    assert(v.size == 0);
    assert(v.capacity == 1);
}


//❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡

void test_pushBack_fullVector1() {
    vector v = createVector(0);
    pushBack(&v, 10);
    pushBack(&v, 12);


    assert(v.size == 2);
    assert(v.capacity == 2);
    assert(isFull(&v) == 1);
    assert(v.data[0] == 10);
}

void test_pushBack_fullVector2() {
    vector v = createVector(3);
    pushBack(&v, 10);
    pushBack(&v, 12);


    assert(v.size == 2);
    assert(v.capacity == 3);
    assert(isFull(&v) == 0);
    assert(v.data[0] == 10);
}

void test_pushBack_fullVector3() {
    vector v = createVector(3);
    pushBack(&v, 10);
    pushBack(&v, 12);
    pushBack(&v, 23);

    assert(v.size == 3);
    assert(v.capacity == 3);
    assert(isFull(&v) == 1);
    assert(v.data[0] == 10);
}

//❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡

void test_popBack_notEmptyVector1() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert (v.size == 1);
    popBack(&v);

    assert (v.size == 0);
    assert (v.capacity == 1);
}

void test_popBack_notEmptyVector2() {
    vector v = createVector(0);
    pushBack(&v, 42);
    pushBack(&v, 7);

    assert (v.size == 2);
    popBack(&v);
    popBack(&v);
    assert(isEmpty(&v) == 1);
    assert (v.size == 0);
    assert (v.capacity == 2);
}

//❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡

void test_popBack_notFullVector1() {
    vector v = createVector(3);
    pushBack(&v, 42);
    assert (v.size == 1);
    assert (v.capacity == 3);
    pushBack(&v, 7);
    pushBack(&v, 1);
    pushBack(&v, 5);

    assert (v.size == 4);
    popBack(&v);
    assert (v.size == 3);
    assert (v.capacity == 6);
}

void test_popBack_notFullVector2() {
    vector v = createVector(5);
    pushBack(&v, 42);
    assert (v.size == 1);
    assert (v.capacity == 5);
    pushBack(&v, 7);
    pushBack(&v, 1);
    pushBack(&v, 5);
    pushBack(&v, 6);
    assert(isFull(&v) == 1);
    pushBack(&v, 0);
    pushBack(&v, 56);

    assert (v.size == 7);
    popBack(&v);
    assert (v.size == 6);
    assert (v.capacity == 10);
    assert(v.data[3] == 5);
    assert(isFull(&v) == 0);
}

//❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡

void test_atVector_notEmptyVector1() {
    vector v = createVector(0);
    pushBack(&v, 10);
    popBack(&v);
    assert(&(v.data[0]) == atVector(&v, 0));
}

void test_atVector_notEmptyVector2() {
    vector v = createVector(0);
    pushBack(&v, 10);
    pushBack(&v, 42);
    pushBack(&v, 7);
    popBack(&v);
    assert(&(v.data[1]) == atVector(&v, 1));
    assert(v.data[1] == 42);
}

//❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡

void test_atVector_requestToLastElement1() {
    vector v = createVector(2);
    pushBack(&v, 10);
    pushBack(&v, 42);
    assert(&(v.data[1]) == atVector(&v, 1));
    assert(v.data[1] == 42);
}

void test_atVector_requestToLastElement2() {
    vector v = createVector(4);
    pushBack(&v, 10);
    pushBack(&v, 42);
    pushBack(&v, 7);
    pushBack(&v, 5);
    assert(&(v.data[3]) == atVector(&v, 3));
    assert(v.data[3] == 5);
}

//❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡

void test_back_oneElementInVector() {
    vector v = createVector(0);
    pushBack(&v, 42);
    assert(&(v.data[0]) == back(&v));
    assert(v.data[0] == 42);
}

//❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡

void test_back_elementsInVector1() {
    vector v = createVector(4);
    pushBack(&v, 42);
    pushBack(&v, 10);
    pushBack(&v, 7);
    pushBack(&v, 5);
    assert(&(v.data[3]) == back(&v));
    assert(v.data[3] == 5);
}

void test_back_elementsInVector2() {
    vector v = createVector(5);
    pushBack(&v, 42);
    pushBack(&v, 10);
    pushBack(&v, 7);
    pushBack(&v, 5);
    pushBack(&v, 2);
    pushBack(&v, 1);
    assert(&(v.data[5]) == back(&v));
    assert(v.data[5] == 1);
}

//❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡

void test_front_oneElementInVector() {
    vector v = createVector(0);
    pushBack(&v, 42);
    assert(&(v.data[0]) == front(&v));
    assert(v.data[0] == 42);
}

//❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡

void test_front_elementsInVector() {
    vector v = createVector(5);
    pushBack(&v, 42);
    pushBack(&v, 10);
    pushBack(&v, 7);
    pushBack(&v, 5);
    pushBack(&v, 2);
    pushBack(&v, 1);
    assert(v.data[0] == 42);
    assert(&(v.data[0]) == front(&v));
}

//❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡

void test_front_elementInVector() {
    vector v = createVector(0);
    pushBack(&v, 42);
    popBack(&v);
    assert(&(v.data[0]) == front(&v));
}

//❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡

void test() {
    test_pushBack_emptyVector1();
    test_pushBack_emptyVector2();
    test_pushBack_emptyVector3();
    test_pushBack_emptyVector4();
    test_pushBack_fullVector1();
    test_pushBack_fullVector2();
    test_pushBack_fullVector3();
    test_popBack_notEmptyVector1();
    test_popBack_notEmptyVector2();
    test_popBack_notFullVector1();
    test_popBack_notFullVector2();
    test_atVector_notEmptyVector1();
    test_atVector_notEmptyVector2();
    test_atVector_requestToLastElement1();
    test_atVector_requestToLastElement2();
    test_back_oneElementInVector();
    test_back_elementsInVector1();
    test_back_elementsInVector2();
    test_front_oneElementInVector();
    test_front_elementsInVector();
    test_front_elementInVector();
}

//❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡ ❤ ♡

int main() {
    test();

    return 0;
}