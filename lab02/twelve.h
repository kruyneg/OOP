#pragma once

#include <vector>
#include <string>
#include <iostream>

class Twelve {
    unsigned char *array;
    size_t _size;
    void resize(size_t);
public:
    Twelve();
    Twelve(const size_t &, unsigned char);
    Twelve(const std::initializer_list<unsigned char> &);
    Twelve(const std::string &);
    Twelve(const Twelve&);
    Twelve(Twelve&&) noexcept;
    virtual ~Twelve() noexcept;

    size_t size() const noexcept;
    std::string to_string() const noexcept;
    int64_t to_decimal() const noexcept;

    Twelve operator+(const Twelve &);
    Twelve operator-(const Twelve &);
    Twelve operator=(const Twelve &);
    Twelve operator=(const std::string &);
    bool operator<(const Twelve &);
    bool operator>(const Twelve &);
    bool operator==(const Twelve &);
    bool operator!=(const Twelve &);
    bool operator<=(const Twelve &);
    bool operator>=(const Twelve &);

    friend std::ostream& operator<<(std::ostream&, const Twelve&);
    friend std::istream& operator>>(std::istream&, Twelve&);
};