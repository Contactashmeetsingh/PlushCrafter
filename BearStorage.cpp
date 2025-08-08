#include <iostream>
#include <fstream>
#include "BearStorage.h"

void BearStorage::saveBearsToFile( const std::vector<PlushBear>& Bear ){
    std::ofstream filename("Storage.txt", std::ios::app);   
    if(filename){
        for(int i =0 ; i<Bear.size();i++){
            filename<<Bear[i].getName()<<std::endl;
            filename<<Bear[i].getSize()<<std::endl;
            filename<<Bear[i].getColor()<<std::endl;
            const std::vector<std::string>& acc = Bear[i].getAccessories();
            filename << acc.size() << '\n';
            for(int i=0; i<acc.size(); i++){
                filename<<acc[i]<<std::endl;
            }
            filename << "----"<<std::endl;      
            
        }
        filename.close();
    }
}
std::vector<PlushBear> BearStorage::deleteBearsFromFile ( std::string& bearBoutToGetDeleted){
    std::vector<PlushBear> allBears = loadBearsFromFile();  // Read all bears
    std::vector<PlushBear> filteredBears;
     for (int i = 0; i < allBears.size(); i++) {
        if (allBears[i].getName() != bearBoutToGetDeleted) {
            filteredBears.push_back(allBears[i]);
        }
    }
    std::ofstream fileName("Storage.txt", std::ios::trunc);
    if (!fileName) ;//return bears;
   
    for (int i = 0; i < filteredBears.size(); i++) {
    fileName << filteredBears[i].getName() << '\n';
    fileName << filteredBears[i].getSize() << '\n';
    fileName << filteredBears[i].getColor() << '\n';

    const auto& acc = filteredBears[i].getAccessories();
    fileName << acc.size() << '\n';
    for (const std::string& item : acc) {
        fileName << item << '\n';
    }
    fileName << "----\n";
    }
    fileName.close();
    return filteredBears;
}
std::vector<PlushBear> BearStorage::loadBearsFromFile (){
      std::ifstream filename("Storage.txt");
    std::vector<PlushBear> bears;

    if (!filename) return bears;

    std::string line;
    while (std::getline(filename, line)) {
        PlushBear bear;
        bear.setName(line);

        if (!std::getline(filename, line)) break;
        bear.setColor(line);

        if (!std::getline(filename, line)) break;
        bear.setSize(line);

        if (!std::getline(filename, line)) break;

        int count = 0;
        try {
            count = std::stoi(line);
        } catch (...) {
            std::cerr << "Warning: Failed to parse accessory count. Skipping bear.\n";
            break; // or use continue to skip this bear
        }

        std::vector<std::string> acc;
        for (int i = 0; i < count; i++) {
            if (!std::getline(filename, line)) break;
            acc.push_back(line);
        }
        bear.setAccessories(acc);

        std::getline(filename, line); // skip "----"
        bears.push_back(bear);
    }

    filename.close();
    return bears;
}
