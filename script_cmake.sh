#!/bin/bash
file=CMakeLists.txt
if [ -e $file ] 
then
mkdir build
cd build
chmod ugo+wx build
cmake ..
make
ls -l

else
    echo "Файл CMakeLists.txt НЕ СУЩЕСТВУЕТ!"
    echo "Создание файла CMakeList.txt..."
    echo "cmake_minimum_required(VERSION 3.16.3)" >> $file
    echo "project(main)" >>$file
    echo "set(SOURCES
          main.cpp)" >> $file
    echo "add_executable(\${PROJECT_NAME} \${SOURCES})" >> $file
    echo "target_link_libraries(\${PROJECT_NAME}
            PRIVATE
            SDL2
            SDL2_image
            SDL2_ttf)" >> $file
    vim $file

fi
