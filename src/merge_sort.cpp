#include <iostream>

#include "merge_sort.hpp"

static bool is_base_case(unsigned int n);

static void get_array_half(const int *a, int *part, unsigned int n, half which_half);

static void merge(int *b, const int *c, const int *d, unsigned int n);

//-------------------------------------------------------------------------------

void merge_sort(int *a, unsigned int n) {
    if (is_base_case(n)) {
        return;
    }

    int c[n / 2];
    int d[n / 2];
    get_array_half(a, c, n, half::LEFT);

    for (unsigned int i{0}; i < n / 2; i++) {
        std::cout << c[i] << " ";
    }

    std::cout << std::endl;

    get_array_half(a, d, n, half::RIGHT);

    for (unsigned int i{0}; i < n / 2; i++) {
        std::cout << d[i] << " ";
    }

    std::cout << std::endl;

    merge_sort(c, n / 2);
    merge_sort(d, n / 2);
    merge(a, c, d, n);
}

//-------------------------------------------------------------------------------

bool is_base_case(unsigned int n) {
    return n <= 1;
}

static void get_array_half(const int *a, int *part, unsigned int n, half which_half) {
    unsigned int i{(which_half == half::LEFT)? 0 : n / 2};
    unsigned int j{0};

    for (; i < n; i++) {
        part[j++] = a[i];
    }
}

static void merge(int *b, const int *c, const int *d, unsigned int n) {
    unsigned int i{0};
    unsigned int j{0};

    for (unsigned int k{0}; k < n; k++) {
        if ((i < n / 2) && (j < n / 2)) {
            if (c[i] < d[j]) {
                b[k] = c[i];
                i++;
            }
            else {
                b[k] = d[j];
                j++;
            }
        }
        else {
            if (i >= n / 2) {
                b[k] = d[j];
                j++;
            }
            else {
                b[k] = c[i];
                i++;
            }
        }
    }
}
