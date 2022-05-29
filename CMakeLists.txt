#MAL PROBIEREN, OB ICH FÜR OPENCV, DIE LIBRARIES IDENTISCH, WIE BEI 
#SFML HINZUFÜGEN KANN



cmake_minimum_required(VERSION 2.8)
project(personRecognition)

find_package(OpenCV 4.2 REQUIRED)


include_directories(lib)
add_library(src_cpp
    src/personDetection.cpp
    src/videoStream.cpp
    )
set(NAME_SRC
    src/personDetection.cpp
    src/videoStream.cpp
    src/faceDetection.cpp
    )
set(NAME_HEADERS
    lib/IDetector.hpp
    lib/personDetection.hpp
    lib/videoStream.hpp
    lib/faceDetection.hpp
    )
#INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/lib)
#INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src)
#link_directories( ${CMAKE_BINARY_DIR}/bin)
#link_directories( ${CMAKE_BINARY_DIR}/src)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})


add_executable(personRecognition main/main.cpp  ${NAME_HEADERS} ${NAME_SRC} )

target_link_libraries( personRecognition ${OpenCV_LIBS} src_cpp )

