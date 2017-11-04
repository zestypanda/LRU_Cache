#ifndef INCLUDE_LRU_CACHE_HPP_
#define INCLUDE_LRU_CACHE_HPP_

#include "../include/double_list.hpp"
#include <unordered_map>
/*get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.*/ 

namespace LRU{
template <typename T, typename S>
class LRUCache{
public:
    LRUCache(int capacity) {
        LRU_size = capacity;
    }
    
    bool hasKey (T key) {
        return cacheMap.find(key) != cacheMap.end();
    }
    
    S get(T key) {
        auto itr = cacheMap.find(key);
        if (itr == cacheMap.end())
           throw std::runtime_error("Key not in Cache");
        else {
           cache.push_front(itr->second->key, itr->second->val);
           cache.remove(itr->second);           
           itr->second = cache.head; 
           return itr->second->val;
        }
    }
    
    void set(T key, S value) {
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
private:
    DoubleList<T, S> cache;
    std::unordered_map<T, typename DoubleList<T, S>::template ListNode<T, S>*> cacheMap;
    int LRU_size;
};

} 
#endif // INCLUDE_LRU_CACHE_HPP_
