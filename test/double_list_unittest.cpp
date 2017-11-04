#include "../include/double_list.hpp"
#include "gtest/gtest.h"

using ::testing::InitGoogleTest;

TEST(DoubleListTest, ConstructorTest){
  LRU::DoubleList<int, int> dlist;
  EXPECT_EQ(0, dlist.size);
  ASSERT_EQ(NULL, dlist.head);
  ASSERT_EQ(NULL, dlist.tail);
}

TEST(DoubleListTest, PushfrontTest){
  LRU::DoubleList<int, int> dlist;
  for (int i = 0; i < 5; ++i) 
    dlist.push_front(i,i);
  EXPECT_EQ(5, dlist.size);
  LRU::DoubleList<int, int>::ListNode<int, int> *head = dlist.head;
  LRU::DoubleList<int, int>::ListNode<int, int> *tail = dlist.tail;
  for (int i = 1; i < 5; ++i){
    head = head->next;
    tail = tail->prev;  
  }
  ASSERT_TRUE(head != NULL);
  ASSERT_TRUE(tail != NULL);
  EXPECT_EQ(0, head->val);
  EXPECT_EQ(0, head->key);
  EXPECT_EQ(4, tail->key);
  EXPECT_EQ(4, tail->val);
}

TEST(DoubleListTest, PushPopTest){
  LRU::DoubleList<int, int> dlist;
  for (int i = 0; i < 5; ++i) 
    dlist.push_front(i,i);
  EXPECT_EQ(5, dlist.size);
  EXPECT_EQ(4, dlist.head->val);
  EXPECT_EQ(4, dlist.head->key);
  dlist.pop_front();
  EXPECT_EQ(3, dlist.head->val);
  dlist.pop_front();
  dlist.pop_front();
  EXPECT_EQ(1, dlist.head->val);
  EXPECT_EQ(1, dlist.head->key);
  dlist.pop_front();
  EXPECT_EQ(0, dlist.head->val);
  EXPECT_EQ(0, dlist.head->key);
  EXPECT_EQ(0, dlist.tail->val);
  EXPECT_EQ(0, dlist.tail->key);
  dlist.pop_front();
  EXPECT_TRUE(dlist.head == NULL);
  EXPECT_EQ(NULL, dlist.tail);
  dlist.pop_front();
  ASSERT_EQ(NULL, dlist.head);
  ASSERT_EQ(NULL, dlist.tail);
  for (int i = 0; i < 5; ++i) 
    dlist.push_front(i,i);
  EXPECT_EQ(0, dlist.tail->val);
  EXPECT_EQ(0, dlist.tail->key);
  dlist.pop_back();
  EXPECT_EQ(1, dlist.tail->val);
  EXPECT_EQ(1, dlist.tail->key);
  dlist.pop_back();
  dlist.pop_back();
  dlist.pop_back();
  EXPECT_EQ(4, dlist.tail->val);
  EXPECT_EQ(4, dlist.tail->key);
  dlist.pop_back();
  EXPECT_EQ(NULL, dlist.tail);
  dlist.pop_back();
  ASSERT_EQ(NULL, dlist.head);
  ASSERT_EQ(NULL, dlist.tail);
}

TEST(DoubleListTest, RemoveTest){
  LRU::DoubleList<int, int> dlist;
  for (int i = 0; i < 5; ++i) 
    dlist.push_front(i,i);
  LRU::DoubleList<int, int>::ListNode<int, int> *node = dlist.head;
  dlist.remove(node);
  ASSERT_EQ(3, dlist.head->val);
  ASSERT_EQ(3, dlist.head->key);
  ASSERT_EQ(4, dlist.size);
  node = dlist.head->next;
  dlist.remove(node);
  ASSERT_EQ(1, dlist.head->next->val);
  ASSERT_EQ(3, dlist.size);
  node = dlist.tail;
  dlist.remove(node);
  ASSERT_EQ(1, dlist.tail->val);
  ASSERT_EQ(1, dlist.tail->key);
  ASSERT_EQ(2, dlist.size);
}

int main(int argc, char **argv) {
  InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
