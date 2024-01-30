from selection_sort import selection_sort


def test_selection_sort():
    arr0 = [5, 2, 9, 1, 5, 6]
    assert selection_sort(arr0) == sorted(arr0)

    arr1 = [5, 4, 7, 8, 3, 10, 1]
    assert selection_sort(arr1) == sorted(arr1)

    arr2 = [6, 3, 100, 8, 1]
    assert selection_sort(arr2) == sorted(arr2)
