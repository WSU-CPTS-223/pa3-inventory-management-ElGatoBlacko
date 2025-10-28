#ifndef HASHMAP_H
#define HASHMAP_H

#include <list>
#include <utility>
#include <functional>

template<typename Key, typename Value>
class HashMap{
private:

    std::list<std::pair<Key,Value>> * bucketArray;
    int elementNum;
    int capacity;
    std::hash<Key> hasher;
public:

    HashMap(){
        elementNum = 0;
        capacity = 3;
        bucketArray = new std::list<std::pair<Key,Value>>[capacity];
    }

    ~HashMap(){
        delete[] bucketArray;
    }

    void insert(const Key& key, const Value& value);
    void resize();
    void print();
    
};

#endif

template <typename Key, typename Value>
inline void HashMap<Key, Value>::insert(const Key &key, const Value &value)
{
    //size_t testThing = hasher(key);
    size_t index = hasher(key) %capacity;
    bucketArray[index].push_back({key,value});
    elementNum++;
    resize();
}

template <typename Key, typename Value>
inline void HashMap<Key, Value>::resize()
{
    int newCapacity=0;
    size_t newIndex=0;
    if(static_cast<double>(elementNum)/capacity>0.5){
        newCapacity = capacity*2;
         std::list<std::pair<Key,Value>>* tempArray = new std::list<std::pair<Key,Value>>[newCapacity];
         for(size_t i = 0; i <capacity; i++){
            for(std::pair<Key,Value>& kvPair : bucketArray[i]){

                newIndex = hasher(kvPair.first) % newCapacity;
                tempArray[newIndex].push_back(kvPair);
            }
         }
         delete[] bucketArray;
         bucketArray = tempArray;
         capacity = newCapacity;
    }
}

template <typename Key, typename Value>
inline void HashMap<Key, Value>::print()
{
    std::cout << "HashMap contents:\n";
    for (size_t i = 0; i < capacity; ++i) {
        std::cout << "Bucket " << i << ": ";
        if (bucketArray[i].empty()) {
            std::cout << "(empty)";
        } else {
            for (std::pair<Key,Value>& kvPair : bucketArray[i]) {
                std::cout << "[" << kvPair.first << " → " << kvPair.second << "] ";
            }
        }
        std::cout << "\n";
    }

}
