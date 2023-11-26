#include "NPC.hpp"

bool NPC::is_close(const NPC& other, const int& distance) const {
    return (x - other.x) * (x - other.x)
        + (y - other.y) * (y - other.y) 
        <= distance * distance;
}

void NPC::notify(NPC* attacker, bool win) {
    if (win) {
        for (auto &elem : NPC::observers) {
            elem->update(this, attacker, win);
        }
    }
}

std::ostream& operator<<(std::ostream& out, const NPC& other) {
    return out << "$NPC {" << other.x << ", " << other.y << '}';
}
