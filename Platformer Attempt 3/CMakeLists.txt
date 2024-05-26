cmake_minimum_required(VERSION 3.28)
project(Platformer_Attempt_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(Platformer_Attempt_3 main.cpp
        Character.cpp
        Character.h
        Object.cpp
        Object.h
        Player.cpp
        Player.h
        Geometry.cpp
        Geometry.h
        Platform.cpp
        Platform.h
        Collider.cpp
        Collider.h
        Guide.cpp
        Guide.h
)

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(Platformer_Attempt_3 sfml-system sfml-window sfml-graphics sfml-audio sfml-audio)
