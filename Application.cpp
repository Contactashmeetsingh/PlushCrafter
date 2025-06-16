#include "Application.h"
#include <iostream>  // You need this for cout

#include "PlushBear.h"


using namespace std;

Application::Application(){
    cout<<"hello world"<<endl;
}
void Application::createBear(){
    PlushBear newBear;
    newBear.customize();
    newBear.display();
    bear.push_back(newBear);
}
void Application::bearList() const{
    for(int i=0; i<bear.size();i++){
        std::cout<< i+1<<"."<<bear[i].getName()<<endl;
    }
}
void Application::viewBearByIndex() const{
    int index;
    std::cout<< "Please insert the index number of the bear"<<endl;
    std::cin>>index;
    if(index>0&& index<bear.size()){
        bear[index-1].display();
    }
    cout<<"invald index";
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

