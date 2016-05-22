#include "include/double_list.hpp"
#include "gtest/gtest.h"

using ::testing::InitGoogleTest;

TEST(DoubleListTest, ConstructorTest){
  LRU::DoubleList dlist;
  EXPECT_EQ(0, dlist.size);
  ASSERT_EQ(NULL, dlist.head);
  ASSERT_EQ(NULL, dlist.tail);
}

int main(int argc, char **argv) {
  InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
