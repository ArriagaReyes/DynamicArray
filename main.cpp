#include <cstdio>
#include "./include/Array.hpp"

void printNums(Array& nums, const size_t length) {
    printf("nums: [ ");

    for(size_t i = 0; i < length; i++) {
        printf("%d", nums.at(i));

        if((i + 1 < length)) {
            printf(", ");
        }
    }

    printf(" ]\n");
}

int main() {
    int array[]{ 6, 3, 9, 24, 1, 69 };

    Array nums;

    for(size_t i = 0; i < 6; i++) {
        nums.push(array[i]);
    }

    printNums(nums, nums.length());

    nums.pop();

    printNums(nums, nums.length());

    return 0;
}