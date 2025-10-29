#ifndef HASHMAP_H
#define HASHMAP_H

#include <list>
#include <utility>
#include <functional>
#include <cstddef>
using std::size_t;


template<typename Key, typename Value>
class HashMap{
private:
    //main stucture of hashtable: dynamically allocated array of lists storing pairs
    std::list<std::pair<Key,Value>> * bucketArray;
    //number of items and capacity for load factor calculations
    int elementNum;
    size_t capacity;
    //hash function
    std::hash<Key> hasher;
public:

    //default constructor sets capacity to 1024 buckets
    HashMap(){
        elementNum = 0;
        capacity = 1024;
        bucketArray = new std::list<std::pair<Key,Value>>[capacity];
    }

    //destructor deallocates array
    ~HashMap(){
        delete[] bucketArray;
    }

    //insert function takes key and value and inserts into hashtable, duplicates are allowed, no return
    void insert(const Key& key, const Value& value);
    //checks if load factor is >0.5, if so doubles size of table and rehashes
    void resize();
    //returns list containing all items with given key, empty list if none exist
    std::list<std::pair<Key,Value>> find(const Key& key);
    
}; 

#endif

template <typename Key, typename Value>
inline void HashMap<Key, Value>::insert(const Key &key, const Value &value)
{
    //put key through hash function then mod by capacity to obtain index
    size_t index = hasher(key) %capacity;
    //put pair into list in the given index
    bucketArray[index].push_back({key,value});
    //update number of elements and resize if necessary
    elementNum++;
    resize();
}

template <typename Key, typename Value>
inline void HashMap<Key, Value>::resize()
{
    int newCapacity=0;
    size_t newIndex=0;
    //checks if load factor is >0.5
    if(static_cast<double>(elementNum)/capacity>0.5){
        //double capacity and make new array with updated capacity
        newCapacity = capacity*2;
         std::list<std::pair<Key,Value>>* tempArray = new std::list<std::pair<Key,Value>>[newCapacity];
         //loops through original array
         for(size_t i = 0; i <capacity; i++){
            //loops through list in each bucket
            for(std::pair<Key,Value>& kvPair : bucketArray[i]){
                //rehashes each item and puts in new doubled array
                newIndex = hasher(kvPair.first) % newCapacity;
                tempArray[newIndex].push_back(kvPair);
            }
         }
         //deletes old array, replaces with new, and updates capacity
         delete[] bucketArray;
         bucketArray = tempArray;
         capacity = newCapacity;
    }
}


template <typename Key, typename Value>
inline std::list<std::pair<Key,Value>> HashMap<Key, Value>::find(const Key &key)
{
    //calculates hash value of target key
    size_t targHash = hasher(key) % capacity;
    std::list<std::pair<Key,Value>> collisionless;
    //loops through list stored at the target bucket and adds all items with target key
    for(std::pair<Key,Value> item : bucketArray[targHash]){
        if(item.first == key){
            collisionless.push_back(item);
        }
    }
    return collisionless;
}
