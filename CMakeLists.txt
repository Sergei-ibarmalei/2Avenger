cmake_minimum_required(VERSION 3.16.3)
project(main)

#SET(MYCOMPILE_FLAGS "-Wall")

set(SOURCES
          Decka.cpp
          engine.cpp
          object_list.cpp
          bez.cpp
          al.cpp 
          fl.cpp
          drawable.cpp 
          hero.cpp 
          Ltexture.cpp 
          sdl_init.cpp
          star.cpp
          starsky.cpp
          myrand.cpp
          backgrounds.cpp
          back_fon.cpp
          bullet.cpp
          main.cpp)



add_executable(${PROJECT_NAME} ${SOURCES})


target_link_libraries(${PROJECT_NAME}
            PRIVATE
            SDL2
            SDL2_image
            SDL2_ttf)

target_compile_options(${PROJECT_NAME} PRIVATE
$<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
$<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic >)