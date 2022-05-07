cmake_minimum_required(VERSION 3.10 )

project(personRecognition CXX)


include_directories(lib)
add_subdirectory(src)
find_package(OpenCV 4.2 REQUIRED)

add_executable(personRecognition main/main.cpp)

target_link_libraries(personRecognition PUBLIC 

    "${PROJECT_SOURCE_DIR}/lib"
    "${PROJECT_SOURCE_DIR}/src"
    ${OpenCV_LIBS}
    ${OpenCV_INCLUDE_DIRS}

    src
    
)

target_include_directories(personRecognition PUBLIC 
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}"

        lib
        ${OpenCV_LIBS}
    )
