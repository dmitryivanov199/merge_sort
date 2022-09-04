#include "merge_sort.hpp"

static bool is_base_case(unsigned int n);

//-------------------------------------------------------------------------------

void merge_sort(int *numbers, unsigned int n) {
    if (is_base_case(n)) {
        return;
    }
}

//-------------------------------------------------------------------------------

bool is_base_case(unsigned int n) {
    return (n == 0) || (n == 1);
}
