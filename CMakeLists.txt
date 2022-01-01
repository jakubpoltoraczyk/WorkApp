project(WorkApp)

find_package(Qt5 5.11.3 COMPONENTS Quick REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
    
    applicationservices/applicationservices.cpp
    main.cpp
    rectanglebutton/cpp/rectanglebuttonservice.cpp

    applicationservices/applicationservices.h
    rectanglebutton/cpp/rectanglebuttonservice.h

    qml.qrc
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wpedantic -Wshadow")

set_target_properties(${PROJECT_NAME} PROPERTIES AUTOMOC ON AUTORCC ON)

target_link_libraries(${PROJECT_NAME}
    Qt5::Quick
)
