# Лабораторная работа 2
## Юрков Евгений, М8О-112Б-22
## Вариант 10

Используя в качестве образца класс `Array` (см. ниже), реализовать динамические контейнеры с использованием динамического массива.
- Каждый класс должен быть разделен на интерфейс и реализацию.
- Самостоятельно определить необходимые типы, поля и дополнительные методы.
- Реализовать генерацию исключений в конструкторах и методах при необходимости (использовать стандартные исключения).
- Реализовать арифметические операции: сложение, вычитание, копирование
- Реализовать операции сравнения: (больше, меньше, равно).
- Арифметические операции с присваиванием должны быть реализованы как методы класса.

```
class Array {
public:
    Array();
    Array(const size_t & n, unsigned char t = 0);
    Array(const std::initializer_list< unsigned char> &t);
    Array(const string &t);
    Array(const Array& other);
    Array(Array&& other) noexcept;
    virtual ~Array() noexcept;
};
```

Создать класс `Twelve` для работы с беззнаковыми целыми двенадцатиричными числами, используя для представления числа массив из элементов типа `unsigned char`, каждый из которых является двенадцатиричными цифрой. Младшая цифра имеет меньший индекс (единицы – в нулевом элементе массива).

[main.cpp](main.cpp) - программа для демонстрации работы класса.\
[twelve.h](twelve.h) - заголовочный файл.\
[twelve.cpp](twelve.cpp) - файл с реализацией. \
[test.cpp](test.cpp) - тесты.