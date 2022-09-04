#include <iostream>

#include "merge_sort.hpp"

void fill_a(int *a, unsigned int n);

void print_a(const int *a, unsigned int n);

int main() {
    const unsigned int n{6};
    int *a = new int[n];

    fill_a(a, n);
    std::cout << "Generated array:" << std::endl;
    print_a(a, n);

    merge_sort(a, n);
    std::cout << "Sorted array:" << std::endl;
    print_a(a, n);

    delete [] a;
    return 0;
}

void fill_a(int *a, unsigned int n) {
    srand(time(NULL));

    for (unsigned int i{0}; i < n; i++) {
        a[i] = rand() % 100 + 1;
    }
}

void print_a(const int *a, unsigned int n) {
    for (unsigned int i{0}; i < n; i++) {
        std::cout << a[i] << " ";
    }

    std::cout << std::endl;
}
