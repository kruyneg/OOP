#include "figure.hpp"
#include "triangle.hpp"
#include "square.hpp"
#include "octagon.hpp"
#include "array.hpp"
#include <iostream>
#include <memory>

int main() {
    Array<std::shared_ptr<Figure<double>>> arr;
    std::string query;
    do {
        std::cin >> query;
        
        if (query == "triangle") {
            Triangle<double> t;
            std::cin >> t;
            std::shared_ptr<Figure<double>> newfigure = std::make_shared<Triangle<double>>(t);
            arr.push_back(newfigure);
        }
        else if (query == "square") {
            Square<double> s;
            std::cin >> s;
            std::shared_ptr<Figure<double>> newfigure = std::make_shared<Square<double>>(s);
            arr.push_back(newfigure);
        }
        else if (query == "octagon") {
            Octagon<double> o;
            std::cin >> o;
            std::shared_ptr<Figure<double>> newfigure = std::make_shared<Octagon<double>>(o);
            arr.push_back(newfigure);
        }
        else if (query == "show") {
            for (size_t i = 0; i < arr.size(); ++i) {
                std::cout << i << '\n' << *arr[i] << std::endl;
            }
        }
        else if (query == "pop") {
            arr.pop_back();
        }
        else if (query == "center") {
            size_t ind;
            std::cin >> ind;
            std::cout << arr[ind]->center().first << ' ' << arr[ind]->center().second << std::endl;
        }
        else if (query == "area") {
            size_t ind;
            std::cin >> ind;
            std::cout << static_cast<double>(*arr[ind]) << std::endl;
        }
        else if (query == "cmp") {
            size_t ind1, ind2;
            std::cin >> ind1 >> ind2;
            std::cout << (*arr[ind1] == *arr[ind2]) << std::endl;
        }
        else if (query == "all") {
            double answer = 0;
            for (size_t i = 0; i < arr.size(); ++i) {
                answer += static_cast<double>(*arr[i]);
            }
            std::cout << answer << std::endl;
        }
    } while (query != "exit" && query != "quit");

}