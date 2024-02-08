#include <iostream>
#include "bubble_sort.cpp"

void print_arr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main(void) {
    int arr[] = {5, 2, 9, 1, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    print_arr(arr, n);
    bubble_sort(arr, n);
    print_arr(arr, n);

    return 0;
}