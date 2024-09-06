#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "user.hpp"
#include "post.hpp"
#include "blog.hpp"

void displayMenu() {
    std::cout << "===== Mini Blog System =====" << std::endl;
    std::cout << "1. Create Post" << std::endl;
    std::cout << "2. View Posts" << std::endl;
    std::cout << "3. View Post by ID" << std::endl;
    std::cout << "4. Edit Post" << std::endl;
    std::cout << "5. Delete Post" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "Choose an option: ";
}

int main() {
    Blog blog;
    int choice = 0;

    while (choice != 6) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore(); // Remove newline character left in the buffer
                std::string title, content, author;
                std::cout << "Enter title: ";
                std::getline(std::cin, title);
                std::cout << "Enter content: ";
                std::getline(std::cin, content);
                std::cout << "Enter author: ";
                std::getline(std::cin, author);

                Post newPost(1, title, content, author);
                blog.addPost(newPost);
                newPost.saveToFile(); // Save to file
                std::cout << "Post created successfully!" << std::endl;
                break;
            }
            case 2: {
                blog.displayPosts();
                break;
            }
            case 3: {
                int postId;
                std::cout << "Enter post ID: ";
                std::cin >> postId;
                blog.viewPost(postId);
                break;
            }
            case 4: {
                int postId;
                std::cin.ignore(); // Remove newline character left in the buffer
                std::string newContent;
                std::cout << "Enter post ID to edit: ";
                std::cin >> postId;
                std::cin.ignore();
                std::cout << "Enter new content: ";
                std::getline(std::cin, newContent);
                // Assuming we can access the post object by ID directly
                // and edit it within the Blog class
                blog.editPost(postId, newContent); 
                std::cout << "Post edited successfully!" << std::endl;
                break;
            }
            case 5: {
                int postId;
                std::cout << "Enter post ID to delete: ";
                std::cin >> postId;
                blog.deletePost(postId);
                std::cout << "Post deleted successfully!" << std::endl;
                break;
            }
            case 6:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid option, please try again." << std::endl;
                break;
        }
        if (std::set<int>{1, 2, 3, 4, 5, 6}.count(choice) == 0)
        {
            break;
        }
        
    }

    return 0;
}


