cmake_minimum_required(VERSION 3.20)
project(ListaSpesa)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES Item.h Item.cpp Category.h Category.cpp ShoppingList.h ShoppingList.cpp User.h User.cpp Subject.h Observer.h)
add_executable(ListaSpesa main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(ListaSpesa core)