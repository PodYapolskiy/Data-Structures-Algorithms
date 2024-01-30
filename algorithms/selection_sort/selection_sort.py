def selection_sort(arr: list[int]) -> list[int]:
    n = len(arr)  # number of elements

    for i in range(n):
        min_index = i  # choose min index as cur. first unsorted index

        # iterate over unsorted elements and find index of the minimal elem
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j

        # swap cur first unsorted element with found unsorted min element
        arr[i], arr[min_index] = arr[min_index], arr[i]

    return arr
