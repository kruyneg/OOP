#include "solution.h"

bool is_vowel(char c) {
    char t {tolower(c)};
    if (t == 'a' || t == 'e' || t == 'y' || t == 'u' || t == 'i' || t == 'o') 
        return true;
    else
        return false;
}

int solution(std::string s) {
    int ans {0};
    for (char elem : s) {
        if (is_vowel(elem))
            ++ans;
    }
    return ans;
}