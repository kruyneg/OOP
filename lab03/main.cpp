#include <iostream>
#include <string>
#include <cstring>
#include "triangle.hpp"
#include "square.hpp"
#include "octagon.hpp"

class Array {
    Figure** arr;
    size_t _capacity;
    size_t _size;

    void _resize() {
        Figure** newarr = new Figure* [_capacity * 2];
        // std::cout << "alloc OK\n";

        for (int i = 0; i < _size; ++i) {
            newarr[i] = arr[i];
        }

        // std::cout << "memcpy OK\n";
        delete[] arr;
        // std::cout << "delete OK\n";
        arr = newarr;
        _capacity *= 2;
        newarr = nullptr;
    }
public:
    Array() {
        arr = new Figure*[1];
        _size = 0;
        _capacity = 1;
    }
    ~Array() {
        for (int i = 0; i < _size; ++i) {
            delete arr[i];
        }
        delete[] arr;
        _size = 0;
        _capacity = 0;
    }
    Figure* push_back(Figure* elem) {
        if (_size + 1 > _capacity) {
            _resize();
        }
        arr[_size++] = elem;
        return elem;
    }
    Figure* pop_back() {
        --_size;
        return arr[_size - 1];
    }
    Figure* operator[](size_t ind) {
        return arr[ind];
    }
    size_t size() const {
        return _size;
    }
};


int main() {
    Array arr;

    std::string query;
    do {
        std::cin >> query;
        
        if (query == "triangle") {
            Triangle* newfigure = new Triangle;
            std::cin >> *newfigure;

            arr.push_back(newfigure);
        }
        else if (query == "square") {
            Square* newfigure = new Square;
            std::cin >> *newfigure;

            arr.push_back(newfigure);
        }
        else if (query == "octagon") {
            Octagon* newfigure = new Octagon;
            std::cin >> *newfigure;

            arr.push_back(newfigure);
        }
        else if (query == "show") {
            for (int i = 0; i < arr.size(); ++i) {
                std::cout << i + 1 << '\n' << (*arr[i]) << std::endl;
            }
        }
        else if (query == "pop") {
            arr.pop_back();
        }
        else if (query == "center") {
            int ind;
            std::cin >> ind;
            std::cout << arr[ind - 1]->center().first << ' ' << arr[ind - 1]->center().second << std::endl;
        }
        else if (query == "area") {
            int ind;
            std::cin >> ind;
            std::cout << static_cast<double>(*arr[ind - 1]) << std::endl;
        }
        else if (query == "cmp") {
            int ind1, ind2;
            std::cin >> ind1 >> ind2;
            std::cout << (*arr[ind1 - 1] == *arr[ind2 - 1]) << std::endl;
        }
        else if (query == "all") {
            double answer = 0;
            for (int i = 0; i < arr.size(); ++i) {
                answer += static_cast<double>(*arr[i]);
            }
            std::cout << answer << std::endl;
        }
    } while (query != "exit" && query != "quit");
}