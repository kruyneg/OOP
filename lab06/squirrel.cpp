#include "elf.hpp"
#include "thug.hpp"
#include "squirrel.hpp"
#include <algorithm>

Squirrel::Squirrel(const int& _x, const int& _y) {
    NPC::x = _x;
    NPC::y = _y;
}

void Squirrel::print(std::ostream& out) {
    out << *this;
}

void Squirrel::accept(NPC* attacker, const int& distance) {
    if (dynamic_cast<Thug*>(attacker)) {
        bool win = is_close(*attacker, distance);
        notify(attacker, win);
    }
}

void Squirrel::attach(Observer* observer) {
    NPC::observers.push_back(observer);
}
void Squirrel::detach(Observer* observer) {
    NPC::observers.erase(
        std::find(NPC::observers.begin(), NPC::observers.end(), observer));
}

std::ostream& operator<<(std::ostream& out, const Squirrel& other) {
    return out << "Squirrel {" << other.NPC::x << ", " << other.NPC::y << '}';
}
