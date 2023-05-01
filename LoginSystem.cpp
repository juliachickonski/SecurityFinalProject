#include "LoginSystem.h"
#include <fstream>
#include <vector>
using std::cin;
using std::cout;
using std::string;

std::vector<string> LoginSystem::getFile() {
    std::vector<string> line; // vector to hold usernames and passwords
    std::fstream infile;
    infile.open("userInfo.txt");

    if (!infile.is_open()) { // check for opening error
        cout << "Could not open file" << std::endl;
    }
    if (infile.is_open()) {
        string str;
        while (std::getline(infile, str)) {
            line.push_back(str);
        }
        infile.close();
    }
    return line;
}

void LoginSystem::create_account() {  //https://www.codespeedy.com/add-a-new-line-to-text-file-in-cpp/
    std::ofstream foutput;
    std::ifstream finput;
    finput.open ("userInfo.txt");
    foutput.open ("userInfo.txt",std::ios::app);

    if(finput.is_open()){
        string username;
        string password;
        cout << "Enter your email address: ";
        cin >> username;
        foutput<< std::endl << username;
        cout << "Enter your password: ";
        cin >> password;
        foutput<< std::endl << password;
    }

    finput.close();
    foutput.close();
}

bool LoginSystem::verify_user(){
    std::vector<string> line = getFile();
    cout << "\nUsername:  ";
    cin >> email_input;
    cout << "Password(case-sensitive):  ";
    cin >> password_input;

    bool valid;

    for(int i = 0; i < line.size();i++){
        if(line[i] == email_input && line[i+1] == password_input){
            cout << std::endl<< "Welcome Back Loyal Customer!" << std::endl;
            valid = true;
        }
    }
    if(!valid){
        cout<< "Sorry! Your login credentials are invalid.";
        login();
    }
    return true;
}

void LoginSystem::login() {
    bool cont = false;
    int user_choice;
    do {
        cout
                << "\n\nWelcome! Choose an option to continue: \n[1] Login with existing account \n[2] Create an account to earn"
                   " reward points! \n[3] Continue as Guest\n[";
        cin >> user_choice;
        if (user_choice > 0 && user_choice < 4) { cont = true; }
        else { std::cout << "\n\nInvalid Choice. Try again."; }
    } while (!cont);

    switch(user_choice){
        case 1:
            verify_user();
            break;
        case 2:
            create_account();
            break;
        case 3:
            break;
    }
}