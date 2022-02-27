
cmake_minimum_required(VERSION 3.2)

#file(GLOB HDR_FILES 
#    ${PROJECT_SOURCE_DIR}/src/socket/*.hpp
#    #${PROJECT_SOURCE_DIR}/src/socket/linux/*.hpp
#)
#file(GLOB SRC_FILES 
#    ${PROJECT_SOURCE_DIR}/src/socket/*.cpp
#    #${PROJECT_SOURCE_DIR}/src/socket/linux/*.cpp
#)

set(
    Headers
    logger/logger.hpp
    socket/socket.hpp
    socket/socket_definitions.hpp
)

set(
    Sources
    logger/logger.cpp
    main.cpp
)

add_executable(${PROJECT_NAME} ${Headers} ${Sources})