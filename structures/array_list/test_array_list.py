from array_list import ArrayList


def test_size():
    arr = ArrayList()
    assert arr.size() == 0

    arr.add_first(0)
    assert arr.size() == 1


def test_is_empty():
    arr = ArrayList()
    assert arr.is_empty() == True

    arr.add_first(0)
    assert arr.is_empty() == False


def test_get():
    arr = ArrayList()

    try:
        arr.get(0)
    except IndexError:
        assert arr.size() == 0

    arr.add_first(1)
    assert arr.get(0) == 1


def test_set():
    arr = ArrayList()
    arr.add_first(0)
    arr.set(0, 1)
    assert arr.get(0) == 1


def test_add():
    arr = ArrayList()
    arr.add_first(-1)
    arr.add(0, -2)
    assert arr.get(0) == -2
    assert arr.get(1) == -1


def test_remove():
    arr = ArrayList()
    arr.add_first(0)
    arr.remove(0)
    assert arr.is_empty() == True


def test_add_first():
    arr = ArrayList()
    arr.add_first(-1)
    arr.add_first(-2)
    assert arr.get(0) == -2
    assert arr.get(1) == -1


def test_add_last():
    arr = ArrayList()
    arr.add_last(-2)
    arr.add_last(-1)
    assert arr.get(0) == -2
    assert arr.get(1) == -1


def test_remove_first():
    arr = ArrayList()
    arr.add_first(-1)
    arr.add_first(-2)

    arr.remove_first()

    assert arr.get(0) == -1


def test_remove_last():
    arr = ArrayList()
    arr.add_last(-2)
    arr.add_last(-1)

    arr.remove_last()

    assert arr.get(0) == -2
