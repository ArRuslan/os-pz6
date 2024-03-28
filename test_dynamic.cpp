#include <cstdint>
#include <dlfcn.h>
#include <iostream>
#include <unistd.h>

#include "test_all.h"

typedef int64_t (*add_t)(int64_t, int64_t);

typedef int64_t (*subtract_t)(int64_t, int64_t);

typedef int64_t (*multiply_t)(int64_t, int64_t);

typedef int64_t (*divide_t)(int64_t, int64_t);

int main() {
    void *lib_dyn = dlopen("./liblib_dyn.so", RTLD_LAZY);
    auto add = reinterpret_cast<add_t>(dlsym(lib_dyn, "add_c"));
    auto subtract = reinterpret_cast<subtract_t>(dlsym(lib_dyn, "subtract_c"));
    auto multiply = reinterpret_cast<multiply_t>(dlsym(lib_dyn, "multiply_c"));
    auto divide = reinterpret_cast<divide_t>(dlsym(lib_dyn, "divide_c"));

    test_all(add, subtract, multiply, divide);
    return 0;
}
