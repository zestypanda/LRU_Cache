#include "include/double_list.hpp"
#include "include/LRU_Cache.hpp"
#include "gtest/gtest.h"

using ::testing::InitGoogleTest;

TEST(DoubleListTest, ConstructorTest){
  LRU::DoubleList dlist;
  EXPECT_EQ(0, dlist.size);
  ASSERT_EQ(NULL, dlist.head);
  ASSERT_EQ(NULL, dlist.tail);
}

TEST(LRUCacheTest, WithinCapacityTest){
  LRU::LRUCache cache(5);
  cache.set(1, 2);
  EXPECT_EQ(2, cache.get(1));
  EXPECT_EQ(-1, cache.get(2));
  cache.set(2, 4);
  EXPECT_EQ(4, cache.get(2));
  cache.set(3, 6);
  cache.set(4, 8);
  cache.set(5, 10);
  EXPECT_EQ(6, cache.get(3));
  EXPECT_EQ(8, cache.get(4));  
  EXPECT_EQ(10, cache.get(5));
  cache.set(4, 9);
  EXPECT_EQ(9, cache.get(4));
  EXPECT_EQ(-1, cache.get(6));
  for (int i = 1; i <= 5; ++i)
    cache.set(i, 1);
  EXPECT_EQ(1, cache.get(1));
  EXPECT_EQ(1, cache.get(2));
  EXPECT_EQ(1, cache.get(3));
  EXPECT_EQ(1, cache.get(4));
  EXPECT_EQ(1, cache.get(5));
  EXPECT_EQ(-1, cache.get(6));
}

TEST(LRUCacheTest, ExceedCapacityTest) {
  LRU::LRUCache cache(5);
  for (int i = 1; i <= 5; ++i)
    cache.set(i, i);
  EXPECT_EQ(1, cache.get(1));
  cache.set(6, 8);
  EXPECT_EQ(8, cache.get(6));
  cache.set(11, 11);
  EXPECT_EQ(11, cache.get(11));
  cache.set(12, 12);
  EXPECT_EQ(12, cache.get(12));
  EXPECT_EQ(1, cache.get(1));
  EXPECT_EQ(-1, cache.get(2));
  cache.set(7, 7);
  EXPECT_EQ(-1, cache.get(3));
  cache.set(8, 8);
  cache.set(9, 9);
  cache.set(10, 10);
  EXPECT_EQ(-1, cache.get(2));
  EXPECT_EQ(1, cache.get(1));
}

TEST(LRUCacheTEST, CapacityOneTest){
  LRU::LRUCache cache(1);
  cache.set(1, 2);
  EXPECT_EQ(2, cache.get(1));
  EXPECT_EQ(-1, cache.get(2));
  cache.set(3, 6);
  EXPECT_EQ(-1, cache.get(1));
  EXPECT_EQ(6, cache.get(3));
  cache.set(1, 1);
  EXPECT_EQ(1, cache.get(1));
  EXPECT_EQ(-1, cache.get(3));
}

int main(int argc, char **argv) {
  InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
