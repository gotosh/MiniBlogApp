#include "post.hpp"
#include <chrono>
#include <ctime>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

Post::Post(int id, const std::string& title, const std::string& content, const std::string& author)
    : id(id), title(title), content(content), author(author)
{
    auto now = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(now);
    timestamp = std::ctime(&end_time);
    timestamp.pop_back();
}

// To save post into file
void Post::saveToFile(){
    // Process that save post data to file
    std::string filename = "data/posts/" + title + ".txt";

    std::ofstream file(filename);
    if (!file)
    {
        std::cerr << "Error: Unable to open file for writing: " << std::endl;
        return;
    }
    file << "Title: " << title << std::endl;
    file << "Coontent" << content << std::endl;
    file << "Author: " << author << std::endl;
    file << "Timestamp: " << timestamp << std::endl;

    file.close();
    std::cout << "Post saved to " << filename << std::endl;

}

void Post::loadFromFile(const std::string& filename){
    // Process that read post data from file
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "Error: Unable to open file for reading: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.find("Title: ") == 0)
        {
            title = line.substr(7);
        } else if (line.find("Content: ") == 0)
        {
            content = line.substr(9);
        } else if (line.find("Author: ") == 0)
        {
            author = line.substr(8);
        } else if (line.find("Timestamp: ") == 0)
        {
            timestamp = line.substr(11);
        }    
    }
    file.close();
    std::cout << "Post loaded from " << filename << std::endl;
    
    
}

void Post::edit(const std::string& newContent){
    content = newContent;
    auto now = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(now);
    timestamp = std::ctime(&end_time);
    timestamp.pop_back();

    saveToFile(); // Save post which have been reviced
}

void Post::deletePost() {
    // delete post 
    std::string filename = "data/posts/" + title + ".txt";

    if (fs::remove(filename))
    {
        std::cout << "Post deleted:" << filename << std::endl;
    } else {
        std::cerr << "Error: Unable to delete file:" << filename << std::endl;
    }
    
}

int Post::getId() const {
    return id;
}

std::string Post::getTitle() const {
    return title;
}

std::string Post::getAuthor() const {
    return author;
}

std::string Post::getContent() const {
    return content;
}

std::string Post::getTimestamp() const {
    return timestamp;
}

Post::~Post()
{
}
