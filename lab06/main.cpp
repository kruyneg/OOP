#include <iostream>
#include <vector>
#include "squirrel.hpp"
#include "thug.hpp"
#include "elf.hpp"
#include "observer.hpp"
#include "factory.hpp"


void load(std::vector<std::shared_ptr<NPC>>& array, std::ifstream& file) {
    while (file) {
        array.push_back(factory(file));
    }
    if (!array.empty() && array.back().get() == nullptr)
        array.pop_back();
}

void save(std::vector<std::shared_ptr<NPC>>& array, std::ofstream& file) {
    for (std::shared_ptr<NPC>& elem : array) {
        elem->print(file);
        file << std::endl;
    }
}

int main() {
    ConsoleObserver cobs;
    std::ofstream filelog("log.txt");
    FileObserver fobs(filelog);

    std::vector<std::shared_ptr<NPC>> persons;

    std::string query;
    do {
        std::cin >> query;
        if (query == "load") {
            std::ifstream file_for_load;
            std::string filename;
            std::cin >> filename;
            file_for_load.open(filename);
            load(persons, file_for_load);
        }
        else if (query == "save") {
            std::ofstream file_for_save;
            std::string filename;
            std::cin >> filename;
            file_for_save.open(filename);
            save(persons, file_for_save);
        }
        else if (query == "add") {
            auto new_npc = factory(std::cin);
            persons.push_back(new_npc);
        }
        
    } while(query != "fight");

    for (auto& elem : persons) {
        elem->attach(&cobs);
        elem->attach(&fobs);
    }
    std::cout << "Input a distance" << std::endl;
    
    int distance;
    std::cin >> distance;

    for (auto& defender : persons) {
        for (auto& attacker : persons) {
            defender->accept(attacker.get(), distance);
        }
    }
}