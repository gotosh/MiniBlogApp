#ifndef ID_HPP
#define ID_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>

class id
{
private:
    int postId;
public:
    id(const std::string& username);
    ~id();

    std::string generate_id();
};





#endif