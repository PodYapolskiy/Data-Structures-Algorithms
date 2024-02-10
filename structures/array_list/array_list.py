class ArrayList:
    def __init__(self, capicity: int = 16):
        self.__size = 0
        self.__CAPACITY = capicity
        self.__data: list[object] = self.__CAPACITY * [0]

    ##############
    # OPERATIONS #
    ##############
    def size(self) -> int:
        return self.__size

    def is_empty(self) -> bool:
        return self.__size == 0

    def get(self, i) -> object:
        self._check_index(i)
        return self.__data[i]

    def set(self, i, e) -> None:
        """
        Replaces the element at index i with e.
        Return the replaced element.
        """
        self._check_index(i)

        # expand if it is full
        if self.__size == self.__CAPACITY:
            self._resize()

        # put element
        self.__data[i] = e

    def add(self, i, e) -> None:
        self._check_index(i)

        # expand
        if self.__size == self.__CAPACITY:
            self._resize()

        # shift elements to the right by 1
        for j in range(self.__size, i, -1):
            self.__data[j - 1], self.__data[j] = self.__data[j], self.__data[j - 1]

        self.__data[i] = e  # put element
        self.__size += 1  # increment __size

    def remove(self, i) -> None:
        self._check_index(i)

        # shift elements to the left by 1
        for j in range(i, self.__size - 1, 1):
            self.__data[j], self.__data[j + 1] = self.__data[j + 1], self.__data[j]

        # decrement __size
        self.__size -= 1

    def add_first(self, e) -> None:
        if self.__size == self.__CAPACITY:
            self._resize()

        # shift elements to the right by 1
        for j in range(self.__size, 0, -1):
            self.__data[j - 1], self.__data[j] = self.__data[j], self.__data[j - 1]

        self.__data[0] = e  # put element
        self.__size += 1  # increment __size

    def add_last(self, e) -> None:
        if self.__size == self.__CAPACITY:
            self._resize()

        self.__data[self.__size] = e  # put element
        self.__size += 1  # increment __size

    def remove_first(self) -> None:
        # shift to the left
        for i in range(self.__size - 1):
            self.__data[i], self.__data[i + 1] = self.__data[i + 1], self.__data[i]

        # decrement __size
        self.__size -= 1

    def remove_last(self) -> None:
        self.__size -= 1

    #########
    # UTILS #
    #########
    def _check_index(self, i):
        """Check that index is in the available range."""
        if i >= self.__size or i < 0:
            raise IndexError("Index out of range")

    def _resize(self):
        self.__CAPACITY *= 2
        arr: list[object] = self.__CAPACITY * [0]

        for i in range(self.__size):
            arr[i] = self.__data[i]

        self.__data = arr
