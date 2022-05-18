#cmake_minimum_required(VERSION 3.10 )

#project(personRecognition CXX)

#set(CMAKE_CXX_STANDARd 14)


#            include_directories(lib)
#            add_subdirectory(src)
#            find_package(OpenCV 4.2 REQUIRED)
#
#            add_executable(personRecognition main/main.cpp)
#
#            target_link_libraries(personRecognition PUBLIC 
#
#                #"${PROJECT_SOURCE_DIR}/lib"
#                #"${PROJECT_SOURCE_DIR}/src"
#                ${OpenCV_LIBS}
#                #${OpenCV_INCLUDE_DIRS}
#
#                src
                
#            )
#
#            target_include_directories(personRecognition PUBLIC 
#                    "${PROJECT_BINARY_DIR}"
#                    "${PROJECT_SOURCE_DIR}"
#
#                    lib
#                    #${OpenCV_LIBS}
#                    #${OpenCV_INCLUDE_DIRS}
#                )
cmake_minimum_required(VERSION 2.8)
PROJECT(personRecognition)
find_package(OpenCV 4.2 REQUIRED)
set(NAME_SRC
    src/videoStream.cpp)
set(NAME_HEADERS
    lib/videoStream.hpp)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/lib)
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
#add_executable(personRecognition ${NAME_SRC} ${NAME_HEADERS} )
add_executable(personRecognition main/main.cpp ${NAME_SRC} ${NAME_HEADERS} )

target_link_libraries( personRecognition ${OpenCV_LIBS} )
