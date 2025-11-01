#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// Global variables
string user;
string pass;

void testLogin(){
    cout<< "Please enter username: ";
    cin >> user;

    cout<< "Please enter password: ";
    cin >> pass;

    cout << user << '\n' << pass << endl;
};

void login(){
    int loginAttempt = 0;
    
    while(loginAttempt <= 5){
    
        cout<< "Please enter username: ";
        cin >> user;

        cout<< "Please enter password: ";
        cin >> pass;
        
        ifstream userFile("info.csv"); //holding file

        if (userFile.is_open()){
            string line;
            string savedUser;
            string savedPass;
            bool loggedIn = false;
            while(getline(userFile, line)){
                //Format is "user,password"
                stringstream sstr(line);
                getline(sstr, savedUser, ',');
                getline(sstr, savedPass);

                if (user == savedUser && pass == savedPass){
                    cout<< "\nLogin successful!\n"<<endl;
                    loggedIn = true;
                    break;
                }
            }
            
            userFile.close();

            if (!loggedIn){
                cout<< "\nInvalid user or password"<< endl;
                cout<< "You have " << 5 - loginAttempt << " attempts.\n"<< endl;
                loginAttempt++;
            } else {
                break;
            }

        } else {
            cerr<< "error: unable to open file."<< endl;
        }
    }
};