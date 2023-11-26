#pragma once
#include <list>
#include <memory>
#include "observer.hpp"

enum class NPC_type {
    unknown,
    squirrel,
    thug,
    elf
};

class Squirrel;
class Thug;
class Elf;

class NPC {
protected:
    std::list<Observer*> observers;
    int x;
    int y;
public:
    NPC() = default;
    ~NPC() = default;

    virtual void print(std::ostream&) = 0;

    virtual void accept(NPC*, const int&) = 0;

    virtual void attach(Observer*) = 0;
    virtual void detach(Observer*) = 0;
    virtual void notify(NPC*, bool);

    virtual bool is_close(const NPC&, const int&) const;

    friend std::ostream& operator<<(std::ostream&, const NPC&);
};