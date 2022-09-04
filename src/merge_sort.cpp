#include <iostream>

#include "merge_sort.hpp"

static bool is_base_case(unsigned int n);

static void get_array_half(const int *a, int *part, unsigned int n, half which_half);

static void merge(int *b, unsigned int n, const int *c, unsigned int c_n, const int *d, unsigned int d_n);

//-------------------------------------------------------------------------------

void merge_sort(int *a, unsigned int n) {
    if (is_base_case(n)) {
        return;
    }

    const unsigned int c_n{n / 2};
    const unsigned int d_n{n - n / 2};

    int c[c_n];
    int d[d_n];

    get_array_half(a, c, n, half::LEFT);
    get_array_half(a, d, n, half::RIGHT);

    merge_sort(c, c_n);
    merge_sort(d, d_n);
    
    merge(a, n, c, c_n, d, d_n);
}

//-------------------------------------------------------------------------------

bool is_base_case(unsigned int n) {
    return n <= 1;
}

void get_array_half(const int *a, int *part, unsigned int n, half which_half) {
    unsigned int i{(which_half == half::LEFT)? 0 : n / 2};
    unsigned int j{0};

    for (; i < n; i++) {
        part[j] = a[i];
        j++;
    }
}

void merge(int *b, unsigned int n, const int *c, unsigned int c_n, const int *d, unsigned int d_n) {
    unsigned int i{0};
    unsigned int j{0};

    for (unsigned int k{0}; k < n; k++) {
        if ((i < c_n) && (j < d_n)) {
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
            if (i >= c_n) {
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
