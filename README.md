# LRU_Cache
Implement LRU (Least Recently Used) Cache Class Template in C++ 
using double linked list and unordered_map; 

each node in the linked list contains data members of key and value;

hash map contains pairs of key and pointer to node;

after accessing an existing key, move the node to the front of double linked list, update the map

if the key not in the cache, delete the tail of double linked list, add a new node to the front, update the map 

Perform Unit Test using Google Test
 
 
