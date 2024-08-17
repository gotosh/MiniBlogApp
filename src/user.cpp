
#include "user.hpp"
#include <openssl/md5.h>
#include <fstream>
#include <sstream>
#include <iostream>

User::User(const std::string& username, const std::string& password) : username(username), password(password) {
    // Read user data
    std::ifstream file("data/users.txt");
    if (!file)
    {
        std::cout << "data/users file cannot be opened!";
    }
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string user, passHash;
        if (std::getline(iss, user, ':') && std::getline(iss, passHash)) 
        {
            userDatabase[user] = passHash;  
        }
            
    }
    std::cout << userDatabase[username] << std::endl; 
    
}

bool User::login(const std::string& inputUsername, const std::string& inputPassword) {
    return false;
}

bool User::registerUser(const std::string& newUsername, const std::string& newPassword){
    // Process of new register, such as saving user information into file.
    if (userDatabase.find(newUsername) != userDatabase.end())
    {
        std::cout << "Error: User already exists!" << std::endl;
        return false;
    }
    // To hash password
    std::string hashedPassword = hashPassword(newPassword);
    userDatabase[newUsername] = hashedPassword;
    std::ofstream file("data/users.txt", std::ios::app);
    if (!file)
    {
        std::cerr << "Error: Unable to open users.txt for writing!" << std::endl;
        return false;
    }
    file << newUsername << ":" << hashedPassword << std::endl;
    file.close();

    std::cout << "User registered successfully!" << std::endl;
    return true;
    
    
    std::ofstream ofs(user_filename);
    if (!ofs)
    {
        std::cout << "User data file cannot be opened!" << std::endl;
        return false;
    }
    ofs << newUsername << std::endl;
    std::cout << "Username has written in the file!" << std::endl;
    return false;
}

std::string User::getUsername() const {
    return username;
}

// Function for hashed password
std::string User::hashPassword(const std::string& password){
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)password.c_str(), password.size(), (unsigned char*)&digest);

    char mdString[33];
    for (int i = 0; i < 16; i++)
    {
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);

    }
    return std::string(mdString);
    
}

// Function for authentication
bool User::authenticate(const std::string& username, const std::string& password){
    std::string hashedPassword = hashPassword(password);
    if (userDatabase.find(username) != userDatabase.end())
    {
        return userDatabase[username] == hashedPassword;
    }
    return false;
}

User::~User(){}