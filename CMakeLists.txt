cmake_minimum_required(VERSION 3.20)
project(MyApp LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)
qt_standard_project_setup(REQUIRES 6.8.3)

qt_add_executable(${PROJECT_NAME}
  main.cpp
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/mycounter)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/mybridge)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::Quick
  PRIVATE
    mycounter
    # mybridge
)

set_target_properties(${PROJECT_NAME} PROPERTIES
  MACOSX_BUNDLE TRUE
  MACOSX_BUNDLE_GUI_IDENTIFIER com.raphael.myapp
  MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist.in
  CXX_STANDARD 23
  CXX_STANDARD_REQUIRED ON
  CMAKE_CXX_EXTENSIONS OFF
)

qt_add_resources(${PROJECT_NAME} "resources"
  FILES
    "main.qml"
)
