#include <cstdio>
#include "../include/Array.hpp"

Array::Array() {
    printf("Creating dynamic array\n");

    arrLength = 0;
    arrCapacity = 2;
    arr = new int[arrCapacity];
}

Array::~Array() {
    printf("Deleting dynamic array\n");

    delete arr;
}

bool Array::inBounds(size_t index) {
    if(index < 0 || arrCapacity -1 < index) {
        return false;
    }

    return true;
}

void Array::resize(size_t newCapacity) {
    printf("Resizing array\n");

    int* temp = new int[newCapacity];

    for(size_t i = 0; i < arrLength - 1; i++) {
        temp[i] = arr[i];
    }

    delete arr;
    arr = temp;

    arrCapacity = newCapacity;
}

void Array::push(int value) {
    if(arrCapacity == arrLength) {
        resize(arrCapacity * 2);
    }

    printf("Pushing %d to Array\n", value);
    arr[arrLength] = value;
    arrLength++;
}