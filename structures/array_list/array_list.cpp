#include <iostream>

template <typename T>
class ArrayList {
    private:
    T* m_arr; // pointer to array
    size_t m_size; // counter of current elements
    size_t m_capacity; // max bound of elements

    public:
    // ------------ //
    // CONSTRUCTORS //
    // ------------ //
    // constructor with initial capacity
    ArrayList(int t_capacity) : m_capacity(t_capacity), m_size(0), m_arr(new T[m_capacity]) {}

    // default constructor
    ArrayList() : ArrayList(16) {}

    // destructor
    ~ArrayList() {
        delete[] m_arr;
    }

    // copy constructor
    ArrayList(const ArrayList& other) : m_capacity(other.m_capacity), m_size(other.m_size), m_arr(new T[m_capacity]) {
        for (size_t i = 0; i < m_size; i++) {
            m_arr[i] = other.m_arr[i];
        }
    }

    // move constructor
    ArrayList(ArrayList&& other) noexcept : m_capacity(other.m_capacity), m_size(other.m_size), m_arr(other.m_arr) {
        other.m_array = nullptr;
        other.m_capacity = 0;
        other.m_size = 0;
    }

    // ------------ //
    // OVERLOADINGS //
    // ------------ //
    // copy assignment operator
    ArrayList& operator=(const ArrayList& other) {
        if (this != &other) {
            delete[] m_arr;
            m_capacity = other.m_capacity;
            m_size = other.m_size;
            m_arr = new T[m_capacity];

            for (size_t i = 0; i < m_size; i++) {
                m_arr[i] = other.m_arr[i];
            }
        }
        return *this;
    }

    // move assignment operator
    ArrayList& operator=(ArrayList&& other) noexcept {
        if (this != &other) {
            delete[] m_arr;

            m_arr = other.m_arr;
            m_capacity = other.m_capacity;
            m_size = other.m_size;

            other.m_arr = nullptr;
            other.m_capacity = 0;
            other.m_size = 0;
        }
        return *this;
    }

    // returns the element at the specified index
    T& operator[](int i) {
        checkIndex(i);
        return m_arr[i];
    }

    // overloaded cout operation
    friend std::ostream& operator<<(std::ostream& output, const ArrayList& list) {
        for (int i = 0; i < list.size(); i++) {
            output << list.get(i) << " ";
        }
        output << std::endl;
        return output;
    }

    // ---------- //
    // OPERATIONS //
    // ---------- //
    // O(1)
    size_t size() const {
        return m_size;
    }

    // O(1)
    bool isEmpty() const {
        return m_size == 0;
    }

    // O(1)
    T get(int i) const {
        checkIndex(i);
        return m_arr[i];
    }

    // O(1)
    void set(int i, T e) {
        checkIndex(i);
        m_arr[i] = e; // put element at given index place
    }

    // O(n)
    void add(int i, T e) {
        checkIndex(i);

        if (m_size == m_capacity) {
            resize(); // expands if capacity is reached
        }

        // shift all elements after to the right by 1
        for (int j = m_size; j > i; j--) {
            swap(&m_arr[j - 1], &m_arr[j]);
        }

        m_arr[i] = e; // add element on given index
        m_size++; // increment size
    }

    // O(n)
    void remove(int i) {
        checkIndex(i);

        // shift all elements after i-th element (to remove) to the left
        for (int j = i; j < m_size - 1; j++) {
            swap(&m_arr[j], &m_arr[j + 1]);
        }
        m_size--; // don't forget to decrement size
    }

    // O(n)
    void addFirst(T e) {
        if (m_size == m_capacity) {
            resize(); // expands
        }

        // shift all elements to the right by 1 place
        for (int j = m_size; j > 0; j--) {
            swap(&m_arr[j - 1], &m_arr[j]);
        }

        m_arr[0] = e; // put element at index 0
        m_size++; // incerement size
    }

    // O(1) amortized
    void addLast(T e) {
        if (m_size == m_capacity) {
            resize(); // expands if reached the capacity
        }
        m_arr[m_size++] = e; // put element and increment the size
    }

    // O(n)
    void removeFirst() {
        for (int i = 0; i < m_size - 1; i++) {
            swap(&m_arr[i], &m_arr[i + 1]);
        }
        m_size--; // don't foget to decrement size
    }

    // O(1), semantically is the same as leave m_size - 1 elements
    void removeLast() {
        m_size--; // the only semantical step
    }

    // O(1)
    void clear() {
        m_size = 0;
    }

    private:
    // ----- //
    // UTILS //
    // ----- //
    // throws error if given index is out of range
    void checkIndex(int i) const {
        if (i >= m_size || i < 0) {
            throw std::out_of_range("Index is out of range");
        }
    }

    // key point of array list is its expansion with number of elements increased
    void resize() {
        m_capacity *= 2; // double up capacity
        T* new_arr = new T[m_capacity]; // create a new doubled size array
        for (int i = 0; i < m_size; i++) {
            new_arr[i] = std::move(m_arr[i]); // move all previous data in new array
        }
        delete[] m_arr; // delete old array
        m_arr = new_arr; // assign new array to the member array
    }

    // helper function that swaps 2 elements using their pointers
    void swap(T* a, T* b) {
        T temp = *a;
        *a = *b;
        *b = temp;
    }
};
