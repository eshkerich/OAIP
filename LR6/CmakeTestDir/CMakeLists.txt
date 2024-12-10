cmake_minimum_required(VERSION 3.13)
project(SumProject)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 14)

# Добавление флагов для AddressSanitizer и ThreadSanitizer
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize=thread")
set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fsanitize=address -fsanitize=thread")

# Добавление исходного файла
set(SOURCE_FILES task.cpp)

# Создание исполняемого файла
add_executable(taski ${SOURCE_FILES})


# чтобы собрать симейк нужно 
# создать main.cpp 
# создать CMakeLists.txt
# в терминале прописать
#
# mkdir build
# cd build
# cmake ..
# make
# ./NameOfProgramm
# 

