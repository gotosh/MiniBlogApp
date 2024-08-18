#ifndef BLOG_HPP
#define BLOG_HPP

#include <vector>
#include <string>
#include "post.hpp"
#include "user.hpp"

class Blog {
public:
    // Constructa and destructa
    Blog();
    ~Blog();

    // View all post
    void displayPosts() const;

    // View specific post
    void viewPost(int postId) const;

    // Add user
    void addUser(const User& user);

    // Add post
    void addPost(const Post& post);

    // Edit post
    void editPost(int postId, const std::string& newContent);

    // Delete post
    void deletePost(int postId);

private:
    // Vector for contain users and posts
    std::vector<User> users;
    std::vector<Post> posts;
};

#endif // BLOG_HPP
