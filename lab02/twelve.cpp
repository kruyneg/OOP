#include "twelve.h"
#include <cmath>

Twelve::Twelve() : array(1, '0') {}
Twelve::Twelve(const size_t & n, unsigned char t = '0') {
    if (!((t >= 'A' && t <= 'B') || (t >= '0' && t <= '9')))
        throw std::invalid_argument("character isn't a twelve digit");
    array.resize(n, t);
}
Twelve::Twelve(const std::initializer_list<unsigned char> &t) {
    array.resize(t.size());
    
    int i = t.size() - 1;
    for (unsigned char elem : t) {
        if (!((elem >= 'A' && elem <= 'B') || (elem >= '0' && elem <= '9')))
            throw std::invalid_argument("character isn't a twelve digit");
        array[i--] = elem;
    }
}
Twelve::Twelve(const std::string &t) {
    for (int i = t.size() - 1; i >= 0; --i) {
        if (!((t[i] >= 'A' && t[i] <= 'B') || (t[i] >= '0' && t[i] <= '9')))
            throw std::invalid_argument("character isn't a twelve digit");
        array.push_back(t[i]);
    }
}
Twelve::Twelve(const Twelve& other) {
    array = other.array;
}
Twelve::Twelve(Twelve&& other) noexcept {
    array = other.array;
}
Twelve::~Twelve() { }

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
    return array.size();
}

// Return the value as a string
std::string Twelve::to_string() const noexcept {
    std::string result;
    for (int i = array.size() - 1; i >= 0; --i) {
        result += array[i];
    }
    return result;
}
// Return a number in decimal notation
int64_t Twelve::to_decimal() const noexcept {
    int64_t result = 0;
    for (int i = 0; i < array.size(); ++i) {
        result += to_int(array[i]) * std::pow(12, i);
    }
    return result;
}

Twelve Twelve::operator+(const Twelve &other) {
    const std::vector<unsigned char> *a, *b;
    if (array.size() < other.array.size()){
        a = &other.array;
        b = &array;
    }
    else {
        a = &array;
        b = &other.array;
    }
    Twelve result = Twelve(a->size(), '0');

    int remain = 0;
    for (int i = 0; i < b->size(); ++i) {
        int val = to_int((*a)[i]) + to_int((*b)[i]) + remain;
        result.array[i] = to_char(val % 12);
        remain = val / 12;
    }
    for (int i = b->size(); i < a->size(); ++i) {
        int val = to_int((*a)[i]) + remain;
        result.array[i] = to_char(val % 12);
        remain = val / 12;
    }
    if (remain > 0) {
        result.array.push_back(to_char(remain));
    }

    return result;
}
Twelve Twelve::operator-(const Twelve &other) {
    Twelve result = *this;

    if (*this < other) {
        throw std::underflow_error("Twelve doesn't support negative values");
    }

    int remain = 0;
    for (int i = 0; i < other.array.size(); ++i) {
        int val = to_int(array[i]) - to_int(other.array[i]) - remain;
        result.array[i] = to_char((val % 12 + 12) % 12);
        remain = val < 0 ? 1 : 0;
    }
    if (array.size() > other.array.size())
        result.array[other.array.size()] = to_char(to_int(array[other.array.size()]) - remain);
    while(result.array[result.array.size() - 1] == '0') {
        result.array.pop_back();
    }

    return result;
}
Twelve Twelve::operator=(const Twelve &other) {
    array = other.array;
    return *this;
}
Twelve Twelve::operator=(const std::string &s) {
    *this = Twelve(s);
    return *this;
}
bool Twelve::operator<(const Twelve &other) {
    if (array.size() < other.array.size())
        return true;
    if (array.size() > other.array.size())
        return false;
    
    for (int i = array.size() - 1; i >= 0; --i) {
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
    if (array.size() > other.array.size())
        return true;
    if (array.size() < other.array.size())
        return false;
    
    for (int i = array.size() - 1; i >= 0; --i) {
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
    if (array.size() != other.array.size())
        return false;
    
    for (int i = array.size() - 1; i >= 0; --i) {
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