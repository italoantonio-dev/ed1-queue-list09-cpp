cmake_minimum_required(VERSION 3.10)
project(ed1_queue_list09 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

add_executable(ed1_queue_list09
    main.cpp
    src/Exer01_ImmediateShiftQueue.cpp
    src/Exer02_StackBasedQueue.cpp
    src/Exer03_OutputRestrictedDeque.cpp
    src/Exer04_PreservedCountQueue.cpp
    src/Exer05_MergeSortedQueues.cpp
    src/Exer06_SplitEvenOddQueue.cpp
)

target_include_directories(ed1_queue_list09 PRIVATE ${CMAKE_SOURCE_DIR}/include)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(ed1_queue_list09 PRIVATE -Wall -Wextra -pedantic)
endif()
