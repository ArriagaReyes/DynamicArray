#include <cstdio>

struct Array {
    Array();
    ~Array();

    int at(size_t);
    size_t capacity();
    int deleteAt(size_t);
    int find(int);
    bool insert(size_t, int);
    bool isEmpty();
    size_t length();
    int pop();
    bool prepend(int);
    void push(int);
    int remove(int);

private:
    bool inBounds(size_t);
    void resize(size_t);

    int* arr;
    size_t arrCapacity;
    size_t arrLength;
};
