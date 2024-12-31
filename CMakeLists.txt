cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file"
)

project(iris-link-backend CXX)

add_executable(${PROJECT_NAME} main.cc)

find_package(cryptopp CONFIG REQUIRED)
find_package(Drogon CONFIG REQUIRED)
find_package(magic_enum CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE
        cryptopp::cryptopp
        Drogon::Drogon
        magic_enum::magic_enum)

target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/models)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/controllers CONTROLLERS)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/filters FILTERS)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/models MODELS)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/plugins PLUGINS)

target_sources(${PROJECT_NAME}
        PRIVATE
        ${CONTROLLERS}
        ${FILTERS}
        ${MODELS}
        ${PLUGINS})

add_subdirectory(test)
