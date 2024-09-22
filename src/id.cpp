#include "id.hpp"

id::id(const std::string& username)
{
}   

id::~id()
{
}

std::string id::generate_id() {
    auto now_time = std::chrono::system_clock::now();
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now_time);
    std::tm now_tm = *std::localtime(&now_time_t);
    std::stringstream ss;
    ss << std::put_time(&now_tm, "%Y%m%d-%H%M%S");
    std::string id = ss.str();
    
    return id;
}