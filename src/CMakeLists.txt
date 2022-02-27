
cmake_minimum_required(VERSION 3.2)

file(GLOB HDR_FILES 
    ${PROJECT_SOURCE_DIR}/src/socket/*.hpp
    #${PROJECT_SOURCE_DIR}/src/socket/linux/*.hpp
)
file(GLOB SRC_FILES 
    ${PROJECT_SOURCE_DIR}/src/socket/*.cpp
    #${PROJECT_SOURCE_DIR}/src/socket/linux/*.cpp
)


add_executable(${PROJECT_NAME} ${SRC_FILES} ${HDR_FILES})