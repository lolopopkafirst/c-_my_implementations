

#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <string>
#include <list>



class Cache{
    private:
        std::list <std::pair<int, int>> lru;
        std::unordered_map<int, decltype(lru.begin())> cache;
        int size;
    public:
        explicit Cache(int sz) : size(sz) {}
        int get(int key){
            if(cache.count(key) <= 0) return -1;
            auto iter = cache[key];
            lru.splice(lru.begin(), lru, iter);
            return lru.front().second;
        }
        void put(int key , int value){
            if(cache.count(key) > 0){
                auto iter = cache[key];
                iter->second = value;
                lru.splice(lru.begin(), lru, iter);
                cache[key] = lru.begin();
            }
            else { 
                lru.push_front({key, value});
                cache[key] = lru.begin();
                if(cache.size() > size){
                int to_delete = lru.back().first;
                lru.pop_back();
                cache.erase(to_delete);
            }
            }
            
        }
        void print(){
            std::cout << "{";
            for(auto& pr : lru){
                std::cout << "{ " << pr.first << ", " << pr.second << "} ,"; 
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
    Cache a(2);
    a.put(1, 2);
    a.put(2, 3);
    a.put(4, 3);
    a.put(5, 3);
    a.print();
    a.print_data();

}
