project(WorkApp)

find_package(Qt5 5.11.3 COMPONENTS Quick Widgets REQUIRED)
find_package(nlohmann_json REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
    
    controller/controller.cpp
    customdialog/cpp/customdialogservice.cpp
    dataservice/dataservice.cpp
    loginwindow/cpp/loginwindowservice.cpp
    main.cpp

    controller/controller.h
    customdialog/cpp/customdialogservice.h
    dataservice/dataservice.h
    dataset/inputcomponentdataset.h
    dataset/customdialogdataset.h
    loginwindow/cpp/loginwindowservice.h

    qml.qrc
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wpedantic -Wshadow")

set_target_properties(${PROJECT_NAME} PROPERTIES AUTOMOC ON AUTORCC ON)

target_link_libraries(${PROJECT_NAME}
    Qt5::Quick
    Qt5::Widgets
    nlohmann_json::nlohmann_json
)
