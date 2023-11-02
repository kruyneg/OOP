#include "twelve.h"
#include <cmath>
#include <cstring>

void Twelve::resize(size_t size) {
    unsigned char* new_array = new unsigned char[size];
    std::cout << "alloc\tOK\n";

    // std::memcpy( new_array, array, size * sizeof(unsigned char));
    for (int i = 0; i < _size; ++i) {
        new_array[i] = array[i];
    }
    std::cout << "memcpy\tOK\n" << "size of array: " << _size << std::endl;

    _size = size;
    delete[] array;
    std::cout << "delete\tOK\n";
    array = new_array;
    new_array = nullptr;
}

Twelve::Twelve() {
    array = new unsigned char;
    *array = '0';
    _size = 1;
}
Twelve::Twelve(const size_t & n, unsigned char t = '0') {
    if (!((t >= 'A' && t <= 'B') || (t >= '0' && t <= '9')))
        throw std::invalid_argument("character isn't a twelve digit");
    array = new unsigned char [n];
    _size = n;
    for (int i = 0; i < _size; ++i) {
        array[i] = t;
    }
}
Twelve::Twelve(const std::initializer_list<unsigned char> &t) {
    array = new unsigned char[t.size()];
    _size = t.size();

    int i = t.size() - 1;
    for (unsigned char elem : t) {
        if (!((elem >= 'A' && elem <= 'B') || (elem >= '0' && elem <= '9')))
            throw std::invalid_argument("character isn't a twelve digit");
        array[i--] = elem;
    }
}
Twelve::Twelve(const std::string &t) {
    array = new unsigned char[t.size()];
    _size = t.size();
    
    int i = t.size() - 1;
    for (unsigned char elem : t) {
        if (!((elem >= 'A' && elem <= 'B') || (elem >= '0' && elem <= '9')))
            throw std::invalid_argument("character isn't a twelve digit");
        array[i--] = elem;
    }
}
Twelve::Twelve(const Twelve& other) {
    array = new unsigned char[other._size];
    std::memcpy(array, other.array, other._size);
    _size = other._size;
}
Twelve::Twelve(Twelve&& other) noexcept {
    array = other.array;
    _size = other._size;
    other.array = nullptr;
    other._size = 0;
}
Twelve::~Twelve() {
    delete[] array;
    _size = 0;
    array = nullptr;
}

unsigned char to_char(int n) {
    if (n < 10) {
        return n + '0';
    }
    else {
        return n - 10 + 'A';
    }
}
int to_int(unsigned char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    else {
        return c - 'A' + 10;
    }
}

// Number of elements
size_t Twelve::size() const noexcept {
    return _size;
}

// Return the value as a string
std::string Twelve::to_string() const noexcept {
    std::string result;
    for (int i = _size - 1; i >= 0; --i) {
        result += array[i];
    }
    return result;
}
// Return a number in decimal notation
int64_t Twelve::to_decimal() const noexcept {
    int64_t result = 0;
    for (int i = 0; i < _size; ++i) {
        result += to_int(array[i]) * std::pow(12, i);
    }
    return result;
}

Twelve Twelve::operator+(const Twelve &other) {
    const unsigned char *a, *b; // a > b
    size_t size_a, size_b;
    if (_size < other._size){
        a = other.array;
        size_a = other._size;
        b = array;
        size_b = _size;
    }
    else {
        b = other.array;
        a = array;
        size_a = _size;
        size_b = other._size;

    }
    Twelve result = Twelve(size_a, '0');

    int remain = 0;
    for (int i = 0; i < size_b; ++i) {
        int val = to_int(a[i]) + to_int(b[i]) + remain;
        result.array[i] = to_char(val % 12);
        remain = val / 12;
    }
    for (int i = size_b; i < size_a; ++i) {
        int val = to_int(a[i]) + remain;
        result.array[i] = to_char(val % 12);
        remain = val / 12;
    }
    if (remain > 0) {
        result.resize(result._size + 1);
        result.array[result._size - 1] = to_char(remain);
    }

    return result;
}
Twelve Twelve::operator-(const Twelve &other) {
    Twelve result = *this;

    if (*this < other) {
        throw std::underflow_error("Twelve doesn't support negative values");
    }

    int remain = 0;
    for (int i = 0; i < other._size; ++i) {
        int val = to_int(array[i]) - to_int(other.array[i]) - remain;
        result.array[i] = to_char((val + 12) % 12);
        remain = val < 0 ? 1 : 0;
    }
    for (int i = other._size; i < _size; ++i) {
        int val = to_int(array[i]) - remain;
        result.array[i] = to_char((val + 12) % 12);
        remain = val < 0 ? 1 : 0;
    }

    int cnt_zero = 0;
    for (int i = result._size - 1; i > 0; --i) {
        if (result.array[i] == '0') {
            ++cnt_zero;
        }
        else {
            break;
        }
    }
    result.resize(result._size - cnt_zero);

    return result;
}
Twelve Twelve::operator=(const Twelve &other) {
    resize(other._size);

    for (int i = 0; i < _size; ++i) {
        array[i] = other.array[i];
    }

    return *this;
}
Twelve Twelve::operator=(const std::string &s) {
    *this = Twelve(s);

    return *this;
}
bool Twelve::operator<(const Twelve &other) {
    if (_size < other._size)
        return true;
    if (_size > other._size)
        return false;
    
    for (int i = _size - 1; i >= 0; --i) {
        if (array[i] < other.array[i]) {
            return true;
        }
        if (array[i] > other.array[i]) {
            return false;
        }
    }

    return false;
}
bool Twelve::operator>(const Twelve &other) {
    if (_size > other._size)
        return true;
    if (_size < other._size)
        return false;
    
    for (int i = _size - 1; i >= 0; --i) {
        if (array[i] > other.array[i]) {
            return true;
        }
        if (array[i] < other.array[i]) {
            return false;
        }
    }

    return false;
}
bool Twelve::operator==(const Twelve &other) {
    if (_size != other._size)
        return false;
    
    for (int i = _size - 1; i >= 0; --i) {
        if (array[i] != other.array[i]) {
            return false;
        }
    }

    return true;
}
bool Twelve::operator!=(const Twelve &other) {
    return !(*this == other);
}
bool Twelve::operator<=(const Twelve &other) {
    return !(*this > other);
}
bool Twelve::operator>=(const Twelve &other) {
    return !(*this < other);
}

std::ostream& operator<<(std::ostream& cout, const Twelve& num) {
    return cout << num.to_string();
}
std::istream& operator>>(std::istream& cin, Twelve& num) {
    std::string val;
    cin >> val;
    num = val;
    return cin;
}