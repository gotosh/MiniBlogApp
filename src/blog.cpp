#include "blog.hpp"
#include <iostream>
#include <iomanip>

// 投稿の一覧を表示する
void Blog::displayPosts() const {
    std::cout << "=== Post List ===" << std::endl;

    for (const auto& post : posts) {
        std::cout << "ID: " << post.getId() << " | Title: " << post.getTitle()
                  << " | Author: " << post.getAuthor() << " | Timestamp: " << post.getTimestamp() << std::endl;
    }

    std::cout << "=================" << std::endl;
}

// 特定の投稿を表示する
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

// ユーザーを追加する
void Blog::addUser(const User& user) {
    users.push_back(user);
}

// 投稿を追加する
void Blog::addPost(const Post& post) {
    posts.push_back(post);
}

// コンストラクタとデストラクタ (必要に応じて実装)
Blog::Blog() {
    // 初期化処理 (必要であれば)
}

Blog::~Blog() {
    // 後処理 (必要であれば)
}
