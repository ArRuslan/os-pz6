#pragma once

typedef int64_t (*add_t)(int64_t, int64_t);
typedef int64_t (*subtract_t)(int64_t, int64_t);
typedef int64_t (*multiply_t)(int64_t, int64_t);
typedef int64_t (*divide_t)(int64_t, int64_t);


void test_all(add_t add, subtract_t subtract, multiply_t multiply, divide_t divide);