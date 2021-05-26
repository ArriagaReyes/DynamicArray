#include <cstdio>
#include "./include/Array.hpp"

int main() {
    Array nums;

    size_t i = 0;
    while(i < 5) {
        nums.push(i);
        i++;
    }

    return 0;
}