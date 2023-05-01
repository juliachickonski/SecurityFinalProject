#include <iostream>
#include <fstream>
#include <vector>

#ifndef SECURITYFINALPROJECT_LOGINSYSTEM_H
#define SECURITYFINALPROJECT_LOGINSYSTEM_H

struct User{
    std::string Email;
    std::string Password;
};

class LoginSystem{
public:
    std::vector<std::string> getFile();
    void create_account();
    bool verify_user();
    void login();

private:
    std::string email_input;
    std::string password_input;
    std::string password;
    std::string email;
    bool valid_login;
};
bool check();

bool login_control();

#endif //SECURITYFINALPROJECT_LOGINSYSTEM_H
