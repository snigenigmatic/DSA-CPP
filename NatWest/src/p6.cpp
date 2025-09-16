#include <bits/stdc++.h>
using namespace std;

class LRUCache{
    private:
    int capacity;
    list<pair<int, int>> cacheList; // stores (key, value) pairs
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap; // maps key to list iterator
    public:
    LRUCache(int capacity){
        this->capacity = capacity;
    }
    int get(int key){
        if(cacheMap.find(key) == cacheMap.end()) return -1;
        // Move the accessed key to the front of the list
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        return cacheMap[key]->second;
    }
    int put(int key, int value){
        if(cacheList.size() == capacity && cacheMap.find(key) == cacheMap.end()){
            // Remove the least recently used item
            auto last = cacheList.back();
            cacheMap.erase(last.first);
            cacheList.pop_back();
        }
        if(cacheMap.find(key) != cacheMap.end()){
            cacheMap[key]->second = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        } else {
            cacheList.push_front({key, value});
            cacheMap[key] = cacheList.begin();
        }
        return value;
    }
};

int main() {
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 4);
    cout << lru.get(1) << endl; // returns 1
    lru.put(3, 9);              // evicts key 2
    cout << lru.get(2) << endl; // returns -1 (not found)
    lru.put(4, 16);              // evicts key 1
    cout << lru.get(1) << endl; // returns -1 (not found)
    cout << lru.get(3) << endl; // returns 9
    cout << lru.get(4) << endl; // returns 16
    return 0;
}