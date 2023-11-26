#include "elf.hpp"
#include "thug.hpp"
#include "squirrel.hpp"
#include <algorithm>

Elf::Elf(const int& _x, const int& _y) {
    NPC::x = _x;
    NPC::y = _y;
}

void Elf::print(std::ostream& out) {
    out << *this;
}

void Elf::accept(NPC* attacker, const int& distance) {
    if (dynamic_cast<Squirrel*>(attacker)) {
        bool win = is_close(*attacker, distance);
        notify(attacker, win);
    }
}

void Elf::attach(Observer* observer) {
    NPC::observers.push_back(observer);
}
void Elf::detach(Observer* observer) {
    NPC::observers.erase(
        std::find(NPC::observers.begin(), NPC::observers.end(), observer));
}

std::ostream& operator<<(std::ostream& out, const Elf& other) {
    return out << "Elf {" << other.NPC::x << ", " << other.NPC::y << '}';
}
