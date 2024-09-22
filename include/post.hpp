#ifndef POST_HPP
#define POST_HPP

#include <string>
#include <fstream>
#include <iostream>

class Post
{
private:
    std::string title;
    std::string content;
    std::string author;
    std::string timestamp;
    std::string id;
public:
    Post(std::string id, const std::string& title, const std::string& content, const std::string& author);
    ~Post();
    void saveToFile();
    void loadFromFile(const std::string& filename);
    void edit(const std::string& newContent);
    void deletePost();

    std::string getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getTimestamp() const;
    std::string getContent() const;
    std::string getPost() const;
};


#endif // POST_HPP