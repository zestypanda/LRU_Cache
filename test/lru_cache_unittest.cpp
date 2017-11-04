#include "../include/double_list.hpp"
#include "../include/LRU_Cache.hpp"
#include "gtest/gtest.h"
using namespace std;
using ::testing::InitGoogleTest;
// test <int, int>
TEST(DoubleListTestInt, ConstructorTest){
  LRU::DoubleList<int, int> dlist;
  EXPECT_EQ(0, dlist.size);
  ASSERT_EQ(NULL, dlist.head);
  ASSERT_EQ(NULL, dlist.tail);
}

TEST(LRUCacheTestInt, WithinCapacityTest){
  LRU::LRUCache<int, int> cache(5);
  cache.set(1, 2);
  EXPECT_EQ(2, cache.get(1));
  EXPECT_EQ(false, cache.hasKey(2));
  cache.set(2, 4);
  EXPECT_EQ(4, cache.get(2));
  cache.set(3, 6);
  cache.set(4, 8);
  cache.set(5, 10);
  EXPECT_EQ(6, cache.get(3));
  EXPECT_EQ(8, cache.get(4));  
  EXPECT_EQ(10, cache.get(5));
  cache.set(4, 9);
  EXPECT_EQ(true, cache.hasKey(4));
  EXPECT_EQ(9, cache.get(4));
  EXPECT_EQ(false, cache.hasKey(6));
  for (int i = 1; i <= 5; ++i)
    cache.set(i, 1);
  EXPECT_EQ(1, cache.get(1));
  EXPECT_EQ(1, cache.get(2));
  EXPECT_EQ(1, cache.get(3));
  EXPECT_EQ(1, cache.get(4));
  EXPECT_EQ(1, cache.get(5));
  EXPECT_EQ(false, cache.hasKey(6));
}

TEST(LRUCacheTestInt, ExceedCapacityTest) {
  LRU::LRUCache<int, int> cache(5);
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
  EXPECT_EQ(false, cache.hasKey(2));
  cache.set(7, 7);
  EXPECT_EQ(false, cache.hasKey(3));
  cache.set(8, 8);
  cache.set(9, 9);
  cache.set(10, 10);
  EXPECT_EQ(false, cache.hasKey(2));
  EXPECT_EQ(1, cache.get(1));
}

TEST(LRUCacheTESTInt, CapacityOneTest){
  LRU::LRUCache<int, int> cache(1);
  cache.set(1, 2);
  EXPECT_EQ(2, cache.get(1));
  EXPECT_EQ(false, cache.hasKey(2));
  cache.set(3, 6);
  EXPECT_EQ(false, cache.hasKey(1));
  EXPECT_EQ(6, cache.get(3));
  cache.set(1, 1);
  EXPECT_EQ(1, cache.get(1));
  EXPECT_EQ(false, cache.hasKey(3));
}

// test <char, string>
TEST(DoubleListTestChar, ConstructorTest){
  LRU::DoubleList<char, string> dlist;
  EXPECT_EQ(0, dlist.size);
  ASSERT_EQ(NULL, dlist.head);
  ASSERT_EQ(NULL, dlist.tail);
}

TEST(LRUCacheTestChar, WithinCapacityTest){
  LRU::LRUCache<char, string> cache(5);
  cache.set('a', "hello");
  EXPECT_EQ("hello", cache.get('a'));
  EXPECT_EQ(false, cache.hasKey('c'));
  cache.set('b', "morning");
  EXPECT_EQ("morning", cache.get('b'));
  cache.set('c', "John");
  cache.set('d', "Texas");
  cache.set('e', "China");
  EXPECT_EQ("John", cache.get('c'));
  EXPECT_EQ("Texas", cache.get('d'));  
  EXPECT_EQ("China", cache.get('e'));
  cache.set('d', "New York");
  EXPECT_EQ("New York", cache.get('d'));
  EXPECT_EQ(false, cache.hasKey('h'));
  for (char c = 'a'; c <= 'e'; ++c)
    cache.set(c, "nihao");
  EXPECT_EQ("nihao", cache.get('a'));
  EXPECT_EQ("nihao", cache.get('b'));
  EXPECT_EQ("nihao", cache.get('c'));
  EXPECT_EQ("nihao", cache.get('d'));
  EXPECT_EQ("nihao", cache.get('e'));
  EXPECT_EQ(false, cache.hasKey('m'));
}

TEST(LRUCacheTestChar, ExceedCapacityTest) {
  LRU::LRUCache<char, string> cache(5);
  for (char i = 'a'; i <= 'e'; ++i)
    cache.set(i, "nihao");
  EXPECT_EQ("nihao", cache.get('a'));
  cache.set('f', "friend");
  EXPECT_EQ("friend", cache.get('f'));
  cache.set('j', "joke");
  EXPECT_EQ("joke", cache.get('j'));
  cache.set('k', "kind");
  EXPECT_EQ("kind", cache.get('k'));
  EXPECT_EQ("nihao", cache.get('a'));
  EXPECT_EQ(false, cache.hasKey('b'));
  cache.set('g', "good");
  EXPECT_EQ(false, cache.hasKey('c'));
  cache.set('h', "hello");
  cache.set('i', "inside");
  cache.set('l', "like");
  EXPECT_EQ(false, cache.hasKey('b'));
  EXPECT_EQ("nihao", cache.get('a'));
}

TEST(LRUCacheTESTChar, CapacityOneTest){
  LRU::LRUCache<char, string> cache(1);
  cache.set('a', "above");
  EXPECT_EQ("above", cache.get('a'));
  EXPECT_EQ(false, cache.hasKey('b'));
  cache.set('c', "cool");
  EXPECT_EQ(false, cache.hasKey('a'));
  EXPECT_EQ("cool", cache.get('c'));
  cache.set('a', "ask");
  EXPECT_EQ("ask", cache.get('a'));
  EXPECT_EQ(false, cache.hasKey('c'));
}
int main(int argc, char **argv) {
  InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
