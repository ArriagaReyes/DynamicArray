#include <cstdio>
#include "../include/Array.hpp"

Array::Array() {
    printf("Creating dynamic array\n");
    length = 0;
    capacity = 16;
    arr = new int[capacity];
}

Array::~Array() {
    printf("Deleting dynamic array\n");
    delete arr;
}