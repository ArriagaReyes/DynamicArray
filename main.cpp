#include <cstdio>
#include "./include/Array.hpp"

int main() {
    int array[]{ 6, 3, 9, 24, 1, 69, 6, 3, 9, 24, 1, 69, 5, 32, 15, 72 };

    Array nums;

    for(size_t i = 0; i < 16; i++) {
        nums.push(array[i]);
    }

    nums.print();

    nums.insert(2, 420);

    nums.prepend(12);

    nums.print();

    for(size_t i = 0; i < 18; i++) {
        nums.pop();
    }

    nums.print();

    return 0;
}