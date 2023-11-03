#pragma once
#include <memory>
#include <stddef.h>
#include <stdexcept>

template<class T>
class Array {
    std::shared_ptr<T[]> arr;
    size_t _capacity;
    size_t _size;

    void _resize() {
        std::shared_ptr<T[]> newarr(new T [_capacity * 2]);
        for (int i = 0; i < _size; ++i) {
            newarr[i] = arr[i];
        }
        arr = newarr;
        _capacity *= 2;
        newarr = nullptr;
    }
public:
    Array() {
        arr = std::shared_ptr<T[]>(new T[1]);
        _size = 0;
        _capacity = 1;
    }

    ~Array() {
        _size = 0;
        _capacity = 0;
    }

    T push_back(T elem) {
        if (_size + 1 > _capacity) {
            _resize();
        }
        arr[_size++] = elem;
        return elem;
    }
    T pop_back() {
        --_size;
        if (_size != 0)
            return arr[_size - 1];
        return 0;
    }
    T& operator[](size_t& ind) const {
        if (ind >= _size)
            throw std::invalid_argument("Index out of range.");
        return arr[ind];
    }
    size_t size() const {
        return _size;
    }
};
