cmake_minimum_required(VERSION 3.25)
project(Desktop)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "F:/Application/Qt/6.5.0/mingw_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
# 添加jsoncpp
include_directories(Desktop F:/Application/jsoncpp/include/json)

# 添加curl
#include_directories(Desktop F:/Application/curl/include/)

# 添加httplib
include_directories(Desktop F:/Application/httplib)

# 设置ui路径
set(CMAKE_AUTOUIC_SEARCH_PATHS "assets")

add_executable(Desktop main.cpp assets/clock.ui assets/tool.ui assets/genshinimpact.ui GenshinImpact.h GenshinImpact.cpp ui_GenshinImpact.h Tool.cpp Tool.h Tool.h ui_Tool.h clock.cpp clock.h ui_clock.h includes.h)
target_link_libraries(Desktop
        Qt::Core
        Qt::Gui
        Qt::Widgets
        E:/Desktop/build/lib/libjsoncpp.a
        F:/Application/Qt/Tools/mingw1120_64/x86_64-w64-mingw32/lib/libws2_32.a
        )
#        F:/Application/build/lib/Release/libcurl_imp.lib
if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
