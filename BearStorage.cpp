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
std::vector<PlushBear> BearStorage::loadBearsFromFile (){
    std::ifstream filename("Storage.txt", std::ios::app);
    std::vector<PlushBear> bears;
    if (!filename) return bears;
    std::string line;
    while(std::getline(filename, line)){
        PlushBear bear;
        bear.setName(line);

        std::getline(filename, line);
        bear.setColor(line);

        std::getline(filename, line);
        bear.setSize(line);

        std::getline(filename, line);
        int count = std::stoi(line);
        
        std::vector<std::string> acc;
        for (int i = 0; i < count; ++i) {
            std::getline(filename, line);
            acc.push_back(line);
        }

        bear.setAccessories(acc);

        std::getline(filename, line); // Read and ignore delimiter line
        bears.push_back(bear);
    }
        filename.close();
        return bears;
}
