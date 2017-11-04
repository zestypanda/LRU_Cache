#!/bin/csh -f

set GTEST_DIR = /Users/ig-lianghan/Documents/GitHub/Cpp_Test/googletest/
g++ -isystem ${GTEST_DIR}/include -pthread test/double_list_unittest.cpp ${GTEST_DIR}/Gtest_lib/libgtest.a -o bin/double_list_unittest
g++ -std=c++11 -isystem ${GTEST_DIR}/include -pthread test/lru_cache_unittest.cpp ${GTEST_DIR}/Gtest_lib/libgtest.a -o bin/lru_cache_unittest