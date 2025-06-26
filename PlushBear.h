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
    // Getters
    std::string getName() const ;
    std::string getColor() const ;
    std::string getSize() const ;
    std::vector<std::string> getAccessories() const ;

    // Setters for loading
    void setName(const std::string& n);
    void setColor(const std::string& c) ;
    void setSize(const std::string& s);
    void setAccessories(const std::vector<std::string>& acc) ;

};

#endif