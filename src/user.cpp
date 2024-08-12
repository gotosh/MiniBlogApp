
#include "user.hpp"

User::User(const std::string& username, const std::string& password) : username(username), password(password) {}

bool User::login(const std::string& inputUsername, const std::string& inputPassword) {
    return false;
}

bool User::registerUser(const std::string& newUsername, const std::string& newPassword){
    // Process of new register, such as saving user information into file.
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

User::~User(){}