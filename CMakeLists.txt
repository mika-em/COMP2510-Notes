cmake_minimum_required(VERSION 3.26)
project(FinalReview C)

set(CMAKE_C_STANDARD 11)

add_executable(FinalReview
        Structure.c
        CPreprocessor.c
        CFinalReview.h
        Generics.c
        MemoryAllocation.c
        LinkedList.c)
