CXXFLAGS = -std=c++0x -Wall
GTEST_DIR = /home/lianghan/install

ifeq ($(DEBUG), 1)
	 CXXFLAGS += -O0 -g 
else
	 CXXFLAGS += -O3
endif
CXXFLAGS += -I. -I$(GTEST_DIR)/include -pthread
LDFLAGS = -L$(GTEST_DIR)/lib -lgtest

all: bin/test_double_list
	
bin/test_double_list: test/double_list_unittest.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS) 

clean:
	rm -r bin/*

