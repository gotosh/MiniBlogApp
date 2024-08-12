#include <iostream>
#include <chrono>
#include <string>

#include "user.hpp"
#include "post.hpp"
#include "blog.hpp"

int main(){
   auto now = std::chrono::system_clock::now();
   std::string st = "18:23";
   std::cout << "hello world! open" << std::endl;
   User user1("username1", "password");
   Post post1("My first Post", "This is the current of my first post.", user1.getUsername(), st);

}

