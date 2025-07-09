#include "Application.h"
#include <iostream>  // You need this for cout

#include "PlushBear.h"
#include "BearStorage.h"


using namespace std;

Application::Application(){
    cout<<"hello world"<<endl;

}
void Application::createBear(){
    PlushBear newBear;
    newBear.customize();
    newBear.display();
    bear.push_back(newBear);
    BearStorage storage;
    storage.saveBearsToFile(bear);         // When a bear is created

    
}
void Application::bearList() const{
    BearStorage storage;
    auto loadedBears = storage.loadBearsFromFile();

    for(int i=0; i<loadedBears.size();i++){
        std::cout<< i+1<<"."<<loadedBears[i].getName()<<endl;
    }
    std::cout<<"would you like to delete any bears? YES or NO"<<endl;
    string deletechoice;
    std::cin>>deletechoice;
    if(deletechoice=="no"){
        return;
    }
    else if(deletechoice=="yes"){
        int index;
        string theChosenOne;
        std::cout<< "Please insert the index number of the bear"<<endl;
        std::cin>>index;
        if(index>0&& index<=loadedBears.size()){
             theChosenOne=loadedBears[index-1].getName();
            std::cout<<theChosenOne<<endl;
            storage.deleteBearsFromFile(theChosenOne);
            //std::cout<<"this is deleted now"<<endl;
            std::cout<<"The list now::"<<endl;
            auto updatedBears = storage.loadBearsFromFile(); 
            for(int i=0; i<loadedBears.size();i++){
                std::cout<< i+1<<"."<<updatedBears[i].getName()<<endl;
            }

        }
        else(cout<<"invald index");
    }
    else(cout<<"invald index");
  // bearList = BearStorage::loadBears(); // When app starts or View Bear is selected

}
void Application::viewBearByIndex() const{
    BearStorage storage;
    std::vector<PlushBear> loadedBears = storage.loadBearsFromFile();
    int index;
    std::cout<< "Please insert the index number of the bear"<<endl;
    std::cin>>index;
    if(index>0&& index<=loadedBears.size()){
        loadedBears[index-1].display();
    }
    else(cout<<"invald index");
}
void Application::run(){
    std::cout << "Welcome to PlushCrafter!\n";
    std::cout << "\n1. Create Bear\n2. List Bears\n3. View Bear\n4. Exit\nChoice: ";
    int choice;
    cin>>choice;
    if(choice>0&&choice<5){
        if(choice==1){
            createBear(); //break;
        }
        if(choice==2){
            bearList(); //break;
        }
        if(choice==3){
            viewBearByIndex(); //break;
        }
        if(choice==4){
            return;
        }
    }
    else{cout<<"Invalid"<<endl;}
}

