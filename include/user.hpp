#ifndef USER_HPP
#define USER_HPP

#include <fstream>
#include <string>
#include <iostream>

class User
{
private:
    std::string username;
    std::string password;
    std::string user_filename = "./data/users.txt";
public:
    User(const std::string& username, const std::string& password);
    bool login(const std::string& inputUsernmae, const std::string& inputPassword);
    bool registerUser(const std::string& newUsername, const std::string& newPassword);

    std::string getUsername() const;
    ~User();
};


#endif
