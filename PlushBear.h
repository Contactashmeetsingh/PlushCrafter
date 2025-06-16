#ifndef PLUSHBEAR_H
#define PLUSHBEAR_H

#include <string>
#include <vector>

class PlushBear {
private:
    std::string name;
    std::string color;
    std::string bearSize;
    std::vector<std::string> accessories;

public:
    void customize();
    void display() const;
    std::string getName() const;
};

#endif