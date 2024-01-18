cmake_minimum_required(VERSION 3.20)
project(ListaSpesa)

set(CMAKE_CXX_STANDARD 11)

add_executable(ListaSpesa main.cpp Item.cpp Item.h ShoppingList.cpp ShoppingList.h Observer.h Subject.h User.cpp User.h Category.cpp Category.h)