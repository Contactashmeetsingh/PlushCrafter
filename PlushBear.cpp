#include "PlushBear.h"
#include <iostream>
#include <limits> // For std::numeric_limits


using namespace std;

void PlushBear::customize(){
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "What would you like to be your bear's name?" << endl;
    std::getline(std::cin, name);
    
    cout << "What would you like to be your bear's color?" << endl;
    getline(cin, color);
    
    cout << "What would you like to be your bear's size?" << endl;
    getline(cin, bearSize);
    
    cout << "Add accessories (type 'done' to finish): " << endl;
    string item;
   
    while(true){
    getline(cin, item);
    if (item == "done") {
        break;;
    }
    else{
    accessories.push_back(item);
    cout << "Add another accessory (or type 'done' to finish): ";
    }
    }
}

void PlushBear::display() const {
    std::cout << "\n--- Your Plush Bear ---\n";
    std::cout << "Name: " << name << "\nColor: " << color << "\n";
    std::cout << "Size: " << bearSize << "\n";
    
    if (!accessories.empty()) {
        std::cout << "Accessories:\n";
        for (size_t i = 0; i < accessories.size(); i++) {
            cout << "- " << accessories[i] << endl;     
        }
    } else {
        std::cout << "No accessories added.\n";
    }
}
 // Getters
    std::string PlushBear::getName() const {
        return name; 
    }
    std::string PlushBear::getColor() const { 
        return color; 
    }
    std::string PlushBear::getSize() const { 
        return bearSize; 
    }
    std::vector<std::string> PlushBear::getAccessories() const { 
        return accessories; 
    }

    // Setters for loading
    void PlushBear::setName(const std::string& n) { 
        name = n; 
    }
    void PlushBear::setColor(const std::string& c) {
        color = c; 
        }
    void PlushBear::setSize(const std::string& s) { 
        bearSize = s; 
    }
    void PlushBear::setAccessories(const std::vector<std::string>& acc) { 
        accessories = acc; 
    }