#include "NPC.hpp"

std::shared_ptr<NPC> factory(std::istream&);
std::shared_ptr<NPC> factory(std::string&, const int&, const int&);