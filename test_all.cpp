#include <cstdint>
#include <cstdio>
#include <iostream>
#include "test_all.h"

struct AB {
    int64_t a;
    int64_t b;
};

AB read_ab() {
    AB ab{};
    printf("a: ");
    std::cin >> ab.a;
    printf("b: ");
    std::cin >> ab.b;

    return ab;
}

void test_all(add_t add, subtract_t subtract, multiply_t multiply, divide_t divide) {
    while (true) {
        printf("Select action:\n");
        printf("  0 - Exit\n");
        printf("  1 - Add\n");
        printf("  2 - Subtract\n");
        printf("  3 - Multiply\n");
        printf("  4 - Divide\n");
        printf("Action: ");
        int inp;
        std::cin >> inp;
        switch (inp) {
            case 0:
                return;
            case 1: {
                AB ab = read_ab();
                try {
                    int64_t result = add(ab.a, ab.b);
                    printf("Result: %ld\n", result);
                } catch (std::overflow_error& e) {
                    printf("Error: %s\n", e.what());
                }

                break;
            }
            case 2: {
                AB ab = read_ab();
                try {
                    int64_t result = subtract(ab.a, ab.b);
                    printf("Result: %ld\n", result);
                } catch (std::overflow_error& e) {
                    printf("Error: %s\n", e.what());
                }

                break;
            }
            case 3: {
                AB ab = read_ab();
                try {
                    int64_t result = multiply(ab.a, ab.b);
                    printf("Result: %ld\n", result);
                } catch (std::overflow_error& e) {
                    printf("Error: %s\n", e.what());
                }

                break;
            }
            case 4: {
                AB ab = read_ab();
                try {
                    int64_t result = divide(ab.a, ab.b);
                    printf("Result: %ld\n", result);
                } catch (std::overflow_error& e) {
                    printf("Error: %s\n", e.what());
                }

                break;
            }
            default: continue;
        }
    }
}