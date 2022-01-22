project(WorkApp)

find_package(Qt5 5.11.3 COMPONENTS Quick Widgets REQUIRED)
find_package(nlohmann_json REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
    
    srcback/controller/controller.cpp
    srcback/customdialogservice/customdialogservice.cpp
    srcback/dataservice/dataservice.cpp
    srcback/loginwindowservice/loginwindowservice.cpp
    srcback/windowmanager/windowmanager.cpp
    main.cpp

    srcback/controller/controller.h
    srcback/customdialogservice/customdialogservice.h
    srcback/dataservice/dataservice.h
    srcback/dataset/inputcomponentdataset.h
    srcback/dataset/customdialogdataset.h
    srcback/dataset/windowmanagerdataset.h
    srcback/loginwindowservice/loginwindowservice.h
    srcback/windowmanager/windowmanager.h

    qml.qrc
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wpedantic -Wshadow")

set_target_properties(${PROJECT_NAME} PROPERTIES AUTOMOC ON AUTORCC ON)

target_link_libraries(${PROJECT_NAME}
    Qt5::Quick
    Qt5::Widgets
    nlohmann_json::nlohmann_json
)
