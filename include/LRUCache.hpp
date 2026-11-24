
#pragma once

#include <list>
#include <map>
#include <unordered_map>

struct Entry {
    int key;
    int value;
};

using LruIterator = std::list<Entry>::iterator;
using ExpIterator = std::map<int, int>::iterator;

struct CacheEntry {
    LruIterator lru_it;
    ExpIterator exp_it;
};

class Cache {
private:
    std::list<Entry> lru;
    std::map<int, int> expire;
    std::unordered_map<int, CacheEntry> cache;

    int size;
    int curr_time = 0;
    int ttl;

public:
    Cache(int sz, int time);

    int get(int key);
    void put(int key, int value);
    void removeExpired(int key);

    void print();
    void print_data();
};
