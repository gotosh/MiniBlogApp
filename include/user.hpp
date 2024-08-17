#ifndef USER_HPP
#define USER_HPP

#include <fstream>
#include <string>
#include <iostream>
#include <string>
#include <unordered_map>

class User
{
private:
    std::string username;
    std::string password;
    std::string passwordHash;
    std::unordered_map<std::string, std::string> userDatabase;  // User name and hashed password 
    std::string hashPassword(const std::string& password);
    std::string user_filename = "./data/users.txt";
public:
    User(const std::string& username, const std::string& password);
    bool login(const std::string& inputUsernmae, const std::string& inputPassword);
    bool registerUser(const std::string& newUsername, const std::string& newPassword);

    std::string getUsername() const;
    bool authenticate(const std::string& username, const std::string& password); // Authenticate function
    ~User();
};


#endif
