#include "blog.hpp"
#include <iostream>
#include <iomanip>

// Display all posts
void Blog::displayPosts() const {
    std::cout << "=== Post List ===" << std::endl;

    for (const auto& post : posts) {
        std::cout << "ID: " << post.getId() << " | Title: " << post.getTitle()
                  << " | Author: " << post.getAuthor() << " | Timestamp: " << post.getTimestamp() << std::endl;
    }

    std::cout << "=================" << std::endl;
}

// Display a specific post
void Blog::viewPost(int postId) const {
    for (const auto& post : posts) {
        if (post.getId() == postId) {
            std::cout << "=== Viewing Post ===" << std::endl;
            std::cout << "Title: " << post.getTitle() << std::endl;
            std::cout << "Author: " << post.getAuthor() << std::endl;
            std::cout << "Content: " << post.getContent() << std::endl;
            std::cout << "Timestamp: " << post.getTimestamp() << std::endl;
            std::cout << "====================" << std::endl;
            return;
        }
    }
    std::cerr << "Error: Post with ID " << postId << " not found." << std::endl;
}

// Add user
void Blog::addUser(const User& user) {
    users.push_back(user);
}

// Add post
void Blog::addPost(const Post& post) {
    posts.push_back(post);
}

// Edit post
void Blog::editPost(int postId, const std::string& newContent) {
    for (auto& post : posts)
    {
        if (post.getId() == postId) /// Looking for the correspond post
        {
            post.edit(newContent);
            std::cout << "Post edited successfully!" << std::endl;
            return;
        }
    }
}

// Delete post
void Blog::deletePost(int postId){
    for (auto it = posts.begin(); it != posts.end(); it++)
    {
        if (it->getId() == postId)
        {
            posts.erase(it);
            std::cout << "Post deleted successfully!" << std::endl;
            return;
        }
        
    }
    std::cout << "Post not found!" << std::endl; // If not found match post.
    
}

// Constructa and destructa 
Blog::Blog() {
    // initialize
}

Blog::~Blog() {
}
