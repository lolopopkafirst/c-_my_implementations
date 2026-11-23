

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <utility>
#include <string>
#include <list>


struct Entry{
    int key;
    int value;
};

using LruIterator = std::list<Entry>::iterator;
using ExpIterator = std::map<int, int>::iterator;

struct CacheEntry {
    LruIterator lru_it;
    ExpIterator exp_it;
};

class Cache{
    private:

        std::list <Entry> lru;
        std::map<int, int> expire;
        std::unordered_map<int, CacheEntry> cache; // key and itterators on lru and ttl
        int size;
        int curr_time = 0;
        int ttl; //time to live

    public:

        Cache(int sz, int time) {
            size = sz;
            ttl = time;
        }   

        int get(int key){
            int now = curr_time++;
            if(cache.count(key) <= 0)   return -1;
            auto lru_iter = cache[key].lru_it;
            auto exp_iter = cache[key].exp_it;
            if(exp_iter->first <= now){
                removeExpired(key);
                return -1;
            } 
            lru.splice(lru.begin(), lru, lru_iter);
 
            return lru.front().value;
        }

        void removeExpired(int key){   //delete in lru and expire and cache
            auto lru_iter = cache[key].lru_it;
            auto exp_iter = cache[key].exp_it;

            cache.erase(key);
            lru.erase(lru_iter);
            expire.erase(exp_iter);
        }

        void put(int key , int value){
            if(cache.count(key) > 0){ //update in lru and expire 
                auto lru_iter = cache[key].lru_it;
                lru_iter->value = value;
                lru.splice(lru.begin(), lru, lru_iter);
                cache[key].lru_it = lru.begin();
                
                auto node = expire.extract(cache[key].exp_it);
                node.key() = curr_time + ttl;
                cache[key].exp_it = expire.insert(std::move(node)).position;
            }
            else { 
                lru.push_front({key, value});
                cache[key].lru_it = lru.begin(); //add in lru

                 auto [it, val] = expire.emplace(curr_time + ttl , key); //add in expire
                 cache[key].exp_it = it;
            
                if(cache.size() > size){ //delete in lru and expire
                    int to_delete = lru.back().key;
                    lru.pop_back();
                    auto delete_exp = cache[to_delete].exp_it;
                    cache.erase(to_delete);
                    expire.erase(delete_exp);
                }
            }
            curr_time++;
        }

        void print(){
            std::cout << "{";
            for(auto& pr : lru){
                std::cout << "{ " << pr.key << ", " << pr.value << "} ,"; 
            }
            std::cout << "}" << "\n";
        }

         void print_data(){
            std::cout << "{";
            for(auto& pr : cache){
                std::cout << pr.first << ", ";
            }
            std::cout << "}" << "\n";
        }

};



int main(){

}
