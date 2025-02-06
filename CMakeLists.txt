cmake_minimum_required(VERSION 3.16)

project(OpenCVQmlExampleProject VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)
find_package(Qt6 REQUIRED COMPONENTS Quick)
set(OpenCV_DIR C:/Users/Vishal/Desktop/ADT/external/opencv/build)
find_package(OpenCV REQUIRED)
qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appOpenCVQmlExampleProject
    main.cpp
    cvimageprovider.h
    cvimageprovider.cpp
    res.qrc
    streamer.h streamer.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appOpenCVQmlExampleProject PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appOpenCVQmlExampleProject
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appOpenCVQmlExampleProject
    PRIVATE Qt6::Quick ${OpenCV_LIBS}
)
include(GNUInstallDirs)
install(TARGETS appOpenCVQmlExampleProject
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
