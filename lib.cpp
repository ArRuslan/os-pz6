#include "lib.h"

#include <limits>
#include <stdexcept>

int64_t add(const int64_t a, const int64_t b) {
    if ((b > 0 && a > INT64_MAX - b) || b < 0 && a < INT64_MIN - b)
        throw std::overflow_error("Overflow!!! ");
    return a + b;
}

int64_t subtract(const int64_t a, const int64_t b) {
    if ((b < 0 && a > INT64_MAX + b) || b > 0 && a < INT64_MIN + b)
        throw std::overflow_error("Overflow!!!");
    return a - b;
}

int64_t multiply(const int64_t a, const int64_t b) {
    if (a > 0 && (b > INT64_MAX / a || b < INT64_MIN / a) || a < -1 && (b < INT64_MAX / a || b > INT64_MIN / a) || a == -1 && b == INT64_MIN)
        throw std::overflow_error("Overflow!!!");
    return a * b;
}

int64_t divide(const int64_t a, const int64_t b) {
    if (b == 0)
        throw std::overflow_error("Division by zero!");
    if (a == std::numeric_limits<int64_t>::min() && b == -1)
        throw std::overflow_error("Overflow!!!");
    return a / b;
}

extern "C" {
int64_t add_c(int64_t a, int64_t b) {
    return add(a, b);
}

int64_t subtract_c(int64_t a, int64_t b) {
    return subtract(a, b);
}

int64_t multiply_c(int64_t a, int64_t b) {
    return multiply(a, b);
}

int64_t divide_c(int64_t a, int64_t b) {
    return divide(a, b);
}
}
