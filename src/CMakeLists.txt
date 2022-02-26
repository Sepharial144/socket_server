
set(
    Headers 
    ${PROJECT_SOURCE_DIR}/src/logger/"*.hpp"
)

set(
    Sources
    ${PROJECT_SOURCE_DIR}/src/socket/"*.cpp"
)

add_executable(${PROJECT_NAME} Headers Sources)