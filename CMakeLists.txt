cmake_minimum_required(VERSION 3.20.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project (SearchBall)

set( NAME_SRC
    src/main.cpp  
    src/World.cpp  
    src/Field.cpp  
    src/Planner.cpp  
    src/Robot.cpp  
    src/Util.cpp  
    src/HelpWindow.cpp  
    src/Model.cpp  
)

set( NAME_HEADERS        
    include/World.hpp  
    include/Field.hpp  
    include/Planner.hpp 
    include/Robot.hpp  
    include/Util.hpp  
    include/HelpWindow.hpp 
    include/Model.hpp
)

find_package(OpenCV REQUIRED )

include_directories(
    ${OpenCV_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)


add_executable(SearchBall ${NAME_SRC} ${NAME_HEADERS})

target_link_libraries(SearchBall PRIVATE ${OpenCV_LIBS})
