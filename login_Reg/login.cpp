#include <iostream>
#include "login.h"

using namespace std;

int main(){
    int option;
    
    while(true){
        cout<< "----------------------\n"
            << "Welcome to the System! \n"
            << "Please choose either option: \n"
            << "1. Login\n2. Register\n" << endl;
            
        cout<<"> ";
        cin >> option;

        if (option == 1){
            cout<< "----------------------\n"
            << "\nWelcome Back!\n "<<endl;
            login();
            break;

        } else if (option == 2) {
            cout<< "----------------------\n"
            << "\nUnder construction\n"<<endl;
            break;
            
        } else {
            cout<< "\nThank you, have a nice day!\n"<<endl;
        }
    }
    return 0;
}