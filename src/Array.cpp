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

void Array::decrease() {
    resize(arrCapacity / 2);
}

bool Array::inBounds(size_t index) {
    if(index < 0 || arrCapacity -1 < index) {
        return false;
    }

    return true;
}

void Array::increase() {
    resize(arrCapacity * 2);
}

void Array::resize(size_t newCapacity) {
    printf("Resizing array to %d\n", newCapacity);

    int* temp = new int[newCapacity];

    for(size_t i = 0; i < arrLength; i++) {
        temp[i] = arr[i];
    }

    delete arr;
    arr = temp;

    arrCapacity = newCapacity;
}

int Array::at(size_t index) {
    if(!inBounds(index)) {
        return -1;
    }

    return arr[index];
}

size_t Array::capacity() {
    return arrCapacity;
}

void Array::deleteAt(size_t index) {
    if(!inBounds(index)) {
        return;
    }

    if(arrLength == arrCapacity / 4) {
        decrease();
    }

    for (size_t i = 0; i < arrLength -1; i++) {
        if(index <= i) {
            arr[i] = arr[i + 1];
            arr[i + 1] = 0;
        }
    }

    arrLength--;
}

int Array::find(int value) {
    int result = -1;

    for(size_t i = 0; i < arrLength - 1; i++) {
        if(value == arr[i]) {
            result = i;
            break;
        }
    }

    return result;
}

bool Array::insert(size_t index, int value) {
    if(!inBounds(index)) {
        return false;
    }

    if(arrLength == arrCapacity) {
        increase();
    }

    for(int i = arrLength - 1; i>= 0; i--) {
        arr[i + 1] = arr[i];

        if(index == i) {
            printf("Inserting %d to Array\n", value);
            arr[i] = value;
            arrLength++;
            break;
        }
    }

    return true;
}

bool Array::isEmpty() {
    if(arrLength == 0) {
        return true;
    }

    return false;
}

size_t Array::length() {
    return arrLength;
}

int Array::pop() {
    if(arrLength == arrCapacity / 4) {
        decrease();
    }

    auto const value = arr[arrLength - 1];

    printf("Removing last element, %d\n", value);
    arr[arrLength - 1] = 0;
    arrLength--;

    return value;
}

bool Array::prepend(int value) {
    const auto success = insert(0, value);

    return success;
}

void Array::print() {
    printf("Array has a length of %d. ", arrLength);
    printf("Array: [ ");

    for(size_t i = 0; i < arrLength; i++) {
        printf("%d", at(i));

        if((i + 1 < arrLength)) {
            printf(", ");
        }
    }

    printf(" ]\n");
}

void Array::push(int value) {
    if(arrCapacity == arrLength) {
        increase();
    }

    printf("Pushing %d to Array\n", value);
    arr[arrLength] = value;
    arrLength++;
}

void Array::remove(int value) {
    for (size_t i = 0; i < arrLength -1; i++) {
        if(value == arr[i]) {
            printf("Removing %d\n", arr[i]);
            arr[i] = 0;
            arrLength--;
        }
    }
}