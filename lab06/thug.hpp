#pragma once
#include "NPC.hpp"


class Thug: public NPC {
public:
    Thug(const int&, const int&);

    void print(std::ostream&) override;

    void accept(NPC*, const int&) override;

    void attach(Observer*) override;
    void detach(Observer*) override;

    friend std::ostream& operator<<(std::ostream&, const Thug&);
};
