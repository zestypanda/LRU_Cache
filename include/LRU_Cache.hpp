#ifndef INCLUDE_LRU_CACHE_HPP_
#define INCLUDE_LRU_CACHE_HPP_

#include "include/double_list.hpp"
#include <unordered_map>
/*get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.*/ 

namespace LRU{
class LRUCache{
public:
    LRUCache(int capacity) {
        LRU_size = capacity;
    }
    
    int get(int key) {
        auto itr = cacheMap.find(key);
        if (itr == cacheMap.end())
           return -1;
        else {
           cache.push_front(itr->second->key, itr->second->val);
           cache.remove(itr->second);           
           itr->second = cache.head; 
           return itr->second->val;
        }
    }
    
    void set(int key, int value) {
        auto itr = cacheMap.find(key);
        if (itr == cacheMap.end()) {
           if (cache.size == LRU_size){                  
               cacheMap.erase(cache.tail->key);
               cache.pop_back();    
           }
           cache.push_front(key, value);
           cacheMap[key] = cache.head;           
        }
        else {
           cache.remove(itr->second);
           cache.push_front(key, value);
           itr->second = cache.head;
        }
    }
    DoubleList cache;
    std::unordered_map<int, DoubleList::ListNode*> cacheMap;
    int LRU_size;
};

} 
#endif // INCLUDE_LRU_CACHE_HPP_
