# Лабораторная работа 4
## Юрков Евгений, М8О-112Б-22
## Вариант 24

Разработать шаблоны классов согласно варианту задания. Параметром шаблона должен являться скалярный тип данных задающий тип данных для оси координат. Классы должны иметь только публичные поля. В классах не должно быть методов, только поля. Фигуры являются фигурами вращения (равнобедренными), за исключением трапеции и прямоугольника. Для хранения координат фигур необходимо использовать шаблон `std::pair` (или реализовать свой шаблон `template <class T> Point` в качестве параметра шаблона должен быть тип для переменных
координат).

Например:
```cpp
template <class T>
struct Square{
using vertex_t = std::pair<T,T>;
vertex_t a,b,c,d;
};
```
Создать программу, которая позволяет:
- Запрещается использовать сырые указатели
- Вводить из стандартного ввода `std::cin` фигуры, согласно варианту задания.
- Сохранять созданные фигуры в динамический массив (переиспользовать от предыдущей лабораторной работы) умных указатели на фигур (`std::smart_ptr<Figure*>`)
- Динамический массив должен быть сделан в виде шаблона (параметр шаблона – класс для хранения в массиве `template <class T> Array {...}`)
- Фигуры должны иметь переопределенные операции копирования, сравнения и приведение к типу `double` (вычисление площади)
- Вызывать для всего массива общие функции (1-3 см. выше).Т.е. распечатывать для каждой фигуры в массиве геометрический центр, координаты вершин и площадь.
- Необходимо уметь вычислять общую площадь фигур в массиве.
- Удалять из массива фигуру по индексу;


**Вариант 24:**
| <!-- -->      | <!-- -->        | <!-- -->      |
|:-------------:|:---------------:|:-------------:|
| 8-угольник    | Треугольник     | Квадрат       |

[main.cpp](main.cpp) - программа для демонстрации работы классов.\
[figure.hpp](figure.hpp) - заголовочный файл.\
[triangle.hpp](triangle.hpp) - заголовочный файл.\
[square.hpp](square.hpp) - заголовочный файл.\
[octagon.hpp](octagon.hpp) - заголовочный файл.\
[test.cpp](test.cpp) - тесты.
