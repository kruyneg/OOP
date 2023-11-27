#include "elf.hpp"
#include "thug.hpp"
#include "squirrel.hpp"
#include <algorithm>

Thug::Thug(const int& _x, const int& _y) {
    NPC::x = _x;
    NPC::y = _y;
}

void Thug::print(std::ostream& out) {
    out << *this;
}

void Thug::accept(NPC* attacker, const int& distance) {
    if (dynamic_cast<Elf*>(attacker)) {
        bool win = is_close(*attacker, distance);
        notify(attacker, win);
    }
}

std::ostream& operator<<(std::ostream& out, const Thug& other) {
    return out << "Thug {" << other.NPC::x << ", " << other.NPC::y << '}';
}
