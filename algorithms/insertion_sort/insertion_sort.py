def insertion_sort(arr: list[int]) -> list[int]:
    n = len(arr)  # number of elements

    for i in range(1, n):  # iterate over elems staring with the second
        j = i - 1  # end of sorted subarray

        # condition to go until beginning and to always swap smaller element on later position
        while j >= 0 and arr[j + 1] < arr[j]:
            arr[j + 1], arr[j] = arr[j], arr[j + 1]  # insert smaller element earlier
            j -= 1  # decrement index, return earlier in the array

    return arr
