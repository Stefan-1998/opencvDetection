cmake_minimum_required(VERSION 2.8)
project(personRecognition)

find_package(OpenCV 4.2 REQUIRED)


include_directories(lib)
set(NAME_SRC
    src/personDetection.cpp
    src/videoStream.cpp
    src/faceDetection.cpp
    src/eyeDetection.cpp
    )
set(NAME_HEADERS
    lib/IDetector.hpp
    lib/personDetection.hpp
    lib/videoStream.hpp
    lib/faceDetection.hpp
    lib/eyeDetection.hpp
    )

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})


add_executable(personRecognition main/main.cpp  ${NAME_HEADERS} ${NAME_SRC} )

target_link_libraries( personRecognition ${OpenCV_LIBS}  )

