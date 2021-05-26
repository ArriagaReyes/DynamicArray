#include <cstdio>

struct Array {
    Array();
    ~Array();

    int at(size_t);
    size_t capacity();
    void deleteAt(size_t);
    int find(int);
    bool insert(size_t, int);
    bool isEmpty();
    size_t length();
    int pop();
    bool prepend(int);
    void print();
    void push(int);
    void remove(int);

private:
    void decrease();
    bool inBounds(size_t);
    void increase();
    void resize(size_t);

    int* arr;
    size_t arrCapacity;
    size_t arrLength;
};
