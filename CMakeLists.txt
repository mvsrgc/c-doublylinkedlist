cmake_minimum_required(VERSION 3.0)

project(doubly)

set(CMAKE_CXX_STANDARD 17)

# Add the source files
set(SOURCES
    main.c)

# Add the header files
set(HEADERS)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
