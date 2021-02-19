# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        native-lib

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        native-lib.cpp)

add_library(people-lib
        SHARED
        people/people.cpp
        )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.
#cmake语法学习
set(var message)
message(${var})
message(${CMAKE_CURRENT_LIST_FILE})#文件路径
message(${CMAKE_CURRENT_LIST_DIR})

IF(TRUE)#通过这些语句来编译不同平台的so库
    MESSAGE("THIS IS TRUE")
ENDIF(false)
MESSAGE("THIS IS UN TRUE")

include_directories(people/)#将people文件夹路径放在本地搜索路径下（好处：cpp文件中可以使用include<>进行导入）
find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        native-lib

        #链接动态库  native-lib去关联people
        people-lib
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})