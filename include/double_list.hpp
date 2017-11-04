#ifndef INCLUDE_DOUBLE_LIST_HPP_
#define INCLUDE_DOUBLE_LIST_HPP_

#include <iostream>

namespace LRU {
template<typename T, typename S>
class DoubleList{
public:
  template <typename P, typename Q>
  class ListNode {
  public: 
    P key;
    Q val;
    ListNode<P, Q>* prev;
    ListNode<P, Q>* next;
    ListNode(P key, Q value): 
       key(key), val(value), prev(NULL), next(NULL) 
    {}
  };

  DoubleList(): size(0), head(NULL), tail(NULL)
  {}
  ~DoubleList() {
    while (head != NULL) {
      ListNode<T, S> *current = head;
      head = head->next;
      delete current;
    } 
  }
  void push_front(T key, S value){
    ListNode<T, S> *node = new ListNode<T, S>(key, value);
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

  void remove(ListNode<T, S>* node){
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
    ListNode<T, S>* tmp = head;
    std::cout << "print forward: ";
    while (tmp != NULL) {
      std::cout << '(' << tmp->key << ',' << tmp->val << ")->";
      tmp = tmp->next;
    }
    std::cout << '\n';
  }

  void printBackward(){
    ListNode<T, S>* tmp = tail;
    std::cout << "print backward: ";
    while (tmp != NULL){ 
      std::cout << '(' << tmp->key << ',' << tmp->val << ")<-";
      tmp = tmp->prev;
    }
    std::cout << std::endl;
  }

//private:
  int size;
  ListNode<T, S>* head;
  ListNode<T, S>* tail; 
};

}
#endif // INCLUDE_DOUBLE_LIST_HPP_
