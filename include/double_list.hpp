#ifndef INCLUDE_DOUBLE_LIST_HPP_
#define INCLUDE_DOUBLE_LIST_HPP_

#include <iostream>

namespace LRU {
class DoubleList{
public:
  struct ListNode {  
    int key;
    int val;
    ListNode* prev;
    ListNode* next;
    ListNode(int key, int value): 
       key(key), val(value), prev(NULL), next(NULL) 
    {}
  };

  DoubleList(): size(0), head(NULL), tail(NULL)
  {}
  ~DoubleList() {
    while (head != NULL) {
      ListNode *current = head;
      head = head->next;
      delete current;
    } 
  }
  void push_front(int key, int value){
    ListNode *node = new ListNode(key, value);
    if (head == NULL){
      head = node;
      tail = node;
    }
    else {
      head->prev = node;
      node->next = head;
      head = node;
    }  
    ++size;
  }

  void pop_front(){
    if (head != NULL){
       if (head != tail){ 
          head = head->next;
          head->prev = NULL;
       }
       else { 
          tail = NULL;
          head = NULL;
       }
       --size;
    }
  }

  void pop_back(){
    if (tail != NULL){
       if (head != tail){
          tail = tail->prev;
          tail->next = NULL;
       }
       else {
          tail = NULL;
          head = NULL;
       }
       --size;
    }
  }

  bool empty(){
    return size == 0;
  }

  void remove(ListNode* node){
    if (node == head)
       pop_front();
    else if (node == tail)
       pop_back();
    else {
       node->prev->next = node->next;
       node->next->prev = node->prev;
       --size;       
    }
    delete node;
  }

  void printForward(){
    ListNode* tmp = head;
    std::cout << "print forward: ";
    while (tmp != NULL) {
      std::cout << '(' << tmp->key << ',' << tmp->val << ")->";
      tmp = tmp->next;
    }
    std::cout << '\n';
  }

  void printBackward(){
    ListNode* tmp = tail;
    std::cout << "print backward: ";
    while (tmp != NULL){ 
      std::cout << '(' << tmp->key << ',' << tmp->val << ")<-";
      tmp = tmp->prev;
    }
    std::cout << std::endl;
  }

//private:
  int size;
  ListNode* head;
  ListNode* tail; 
};

}
#endif // INCLUDE_DOUBLE_LIST_HPP_
