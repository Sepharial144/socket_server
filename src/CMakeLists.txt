
cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB HEADER_FILES 
    ${PROJECT_SOURCE_DIR}/src/socket/*.hpp
    #${PROJECT_SOURCE_DIR}/src/socket/linux/*.hpp
)
file(GLOB SOURCE_FILES 
    ${PROJECT_SOURCE_DIR}/src/socket/*.cpp
    #${PROJECT_SOURCE_DIR}/src/socket/linux/*.cpp
)


add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})