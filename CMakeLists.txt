cmake_minimum_required(VERSION 3.0.2)
project(PA1)
add_compile_options(-std=c++11)

include_directories(
  include
)

# # 把路徑丟至source_list
# aux_source_directory(./src source_list)
# # 編譯src底下所有檔案
# add_executable(${PROJECT_NAME} ${source_list})

file(GLOB SOURCES
    include/*.h
    src/main.cpp
    src/student.cpp
)
add_executable(${PROJECT_NAME} ${SOURCES})

MESSAGE(${SOURCES})
