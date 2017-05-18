cmake_minimum_required(VERSION 3.4.1)

add_library(testjni SHARED
            test.c)

# Include libraries needed for hello-jni lib
target_link_libraries(testjni
                      android
                      log)
