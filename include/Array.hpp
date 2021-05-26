#include <cstdio>

struct Array {
    Array();
    ~Array();

private:
    int* arr;
    size_t length;
    size_t capacity;
};
