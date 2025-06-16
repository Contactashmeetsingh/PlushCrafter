#ifndef APPLICATION_H
#define APPLICATION_H

#include "PlushBear.h"

class Application{
    std::vector<PlushBear> bear;
    public:
    Application();
    void run ();
    void createBear() ;
    void bearList() const;
    void viewBearByIndex() const;

};

#endif