#include "post.hpp"
#include <chrono>
#include <ctime>

Post::Post(const std::string& title, const std::string& content, const std::string& author, const std::string& timestamp)
    : title(title), content(content), author(author)
{
    auto now = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(now);
    std::cout << "Current Time and Date: " << std::ctime(&end_time) << std::endl;
}

void Post::saveToFile(){
    // Process that save post data to file
    std::cout << "savefile" << std::endl;

}

void Post::loadFromFile(const std::string& filename){
    // Process that read post data from file
}

void Post::edit(const std::string& newContent){
    content = newContent;
}

void Post::deletePost() {
    // delete post 
}
Post::~Post()
{
}
