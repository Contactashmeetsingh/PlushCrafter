#ifndef BEARSTORAGE_H
#define BEARSTORAGE_H
using namespace std;


#include <iostream>
#include <fstream>
#include "PlushBear.h"

class BearStorage{
public:
    void saveBearsToFile( const std::vector<PlushBear>& Bear);
    std::vector<PlushBear> loadBearsFromFile ();
    std::vector<PlushBear> deleteBearsFromFile( std::string& bearBoutToGetDeleted);
};
#endif