cmake_minimum_required(VERSION 3.10)
project(MiniBlogSystem LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories((${CMAKE_SOURCE_DIR}/include))

find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})
## Designate source files 
set(SOURCES
    src/main.cpp
    src/user.cpp
    src/post.cpp
    src/blog.cpp
)

### Create executable file
add_executable(MiniBlogApp ${SOURCES})
### Link openssl library
target_link_libraries(MiniBlogApp PRIVATE OpenSSL::SSL OpenSSL::Crypto)
# target_link_libraries(MiniBlogApp PRIVATE SomeLibary)
# target_link_libraries(MiniBlogTests PRIVATE SomeLibrary)

