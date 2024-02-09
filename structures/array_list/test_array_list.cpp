#include <iostream>
#include <assert.h>
#include "array_list.cpp"

void test_size(ArrayList<int>& arr) {
    assert(arr.size() == 0);

    arr.addLast(0);
    assert(arr.size() == 1);

    arr.removeLast();
    assert(arr.size() == 0);

    arr.clear();
    std::cout << "size(): passed" << std::endl;
}

void test_is_empty(ArrayList<int>& arr) {
    assert(arr.isEmpty() == true);

    arr.addLast(0);
    assert(arr.isEmpty() == false);

    arr.clear();
    std::cout << "isEmpty(): passed" << std::endl;
}

void test_get(ArrayList<int>& arr) {
    arr.addLast(0);
    arr.addLast(1);

    assert(arr.get(0) == 0);
    assert(arr.get(1) == 1);

    arr.clear();
    std::cout << "get(): passed" << std::endl;
}

void test_set(ArrayList<int>& arr) {
    arr.addLast(0);
    arr.addLast(1);

    arr.set(1, -1);

    assert(arr.get(1) == -1);

    arr.clear();
    std::cout << "set(): passed" << std::endl;
}

void test_add(ArrayList<int>& arr) {
    arr.addLast(0);
    arr.addLast(2);

    arr.add(0, -1);
    arr.add(2, 1);

    assert(arr.get(0) == -1);
    assert(arr.get(1) == 0);
    assert(arr.get(2) == 1);
    assert(arr.get(3) == 2);

    arr.clear();
    std::cout << "add(): passed" << std::endl;
}

void test_remove(ArrayList<int>& arr) {
    arr.addLast(0);
    arr.addFirst(-1);

    arr.remove(0);

    assert(arr.get(0) == 0);

    arr.clear();
    std::cout << "remove(): passed" << std::endl;
}

void test_add_first(ArrayList<int>& arr) {
    arr.addFirst(6);
    arr.addFirst(5);
    arr.addFirst(1);

    assert(arr.get(0) == 1);
    assert(arr.get(1) == 5);
    assert(arr.get(2) == 6);

    arr.clear();
    std::cout << "addFirst(): passed" << std::endl;
}

void test_add_last(ArrayList<int>& arr) {
    arr.addLast(1);
    arr.addLast(5);
    arr.addLast(6);

    assert(arr.get(0) == 1);
    assert(arr.get(1) == 5);
    assert(arr.get(2) == 6);

    arr.clear();
    std::cout << "addLast(): passed" << std::endl;
}

void test_remove_first(ArrayList<int>& arr) {
    arr.addLast(0);
    arr.addLast(1);

    arr.removeFirst();

    assert(arr.get(0) == 1);

    arr.clear();
    std::cout << "removeFirst(): passed" << std::endl;
}

void test_remove_last(ArrayList<int>& arr) {
    arr.addLast(0);
    arr.addLast(1);
    arr.addLast(2);

    arr.removeLast();

    assert(arr.size() == 2);
    assert(arr.get(1) == 1);

    arr.clear();
    std::cout << "removeLast(): passed" << std::endl;
}

int main(void) {
    // [5, 2, 9, 1, 5, 6]

    try {
        // clear in the end of each test
        ArrayList<int> arr;
        test_size(arr);
        test_is_empty(arr);
        test_get(arr);
        test_set(arr);
        test_add(arr);
        test_remove(arr);
        test_add_first(arr);
        test_add_last(arr);
        test_remove_first(arr);
        test_remove_last(arr);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}