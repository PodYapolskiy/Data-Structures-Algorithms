def bubble_sort(arr: list[int]) -> list[int]:
    n = len(arr)  # number of elements

    for i in range(n):  # n times iterates and bubble up the greatest element
        for j in range(n - i - 1):  # iterate until already sorted elements
            if arr[j] > arr[j + 1]:  # compare 2 neighboring elements
                arr[j], arr[j + 1] = arr[j + 1], arr[j]  # swap them if needed

    return arr
