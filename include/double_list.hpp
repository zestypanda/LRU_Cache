#ifndef SRC_DOUBLE_LIST_CPP_
#define SRC_DOUBLE_LIST_CPP_

#include <iostream>

namespace LRU {

struct ListNode {
  int val;  
  ListNode* prev;
  ListNode* next;
  ListNode(int x): val(x), prev(NULL), next(NULL) {}
};

class DoubleList{
public:
  DoubleList(): size(0), head(NULL), tail(NULL)
  {}
  ~DoubleList() {
    while (head != NULL) {
      ListNode *current = head;
      head = head->next;
      delete current;
    } 
  }
  void push_front(int x){
    ListNode *node = new ListNode(x);
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
  }

  void printForward(){
    ListNode* tmp = head;
    std::cout << "print forward: ";
    while (tmp != NULL) {
      std::cout << tmp->val << "->";
      tmp = tmp->next;
    }
    std::cout << '\n';
  }

  void printBackward(){
    ListNode* tmp = tail;
    std::cout << "print backward: ";
    while (tmp != NULL){ 
      std::cout << tmp->val << "<-";
      tmp = tmp->prev;
    }
    std::cout << '\n';
  }

//private:
  int size;
  ListNode* head;
  ListNode* tail; 
};

}
#endif // SRC_DOUBLE_LIST_CPP_
