#include "vector.hpp"
#include <iostream>
int main(){
    std::cout << "after default constructor \n";
    Vector<int> a;
    std::cout << &a << " " << a.size() << " " << a.begin() << " " << a.end() << " " << a.capacity() << "\n";

    std::cout << "after push_backs \n";
    a.push_back(12);
    std::cout << &a << " " << a.size() << " " << a.begin() << " " << a.end() << " " << a.capacity() << "\n";
    a.push_back(13);
    std::cout << &a << " " << a.size() << " " << a.begin() << " " << a.end() << " " << a.capacity() << "\n";
    for(int i : a){
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "after pop_back \n";
    a.pop_back();
    for(int i : a){
        std::cout << i << " ";
    }
    std::cout << "\n";
    
    std::cout << "after pop_back \n";
    a.pop_back();
    for(int i : a){
        std::cout << i << " ";
    }
    std::cout << &a << " " << a.size() << " " << a.begin() << " " << a.end() << " " << a.capacity() << "\n";

    std::cout << "after push_backs, capacity == size \n";
    a.push_back(11);
    a.push_back(12);
    a.push_back(13);
    std::cout << &a << " " << a.size() << " " << a.begin() << " " << a.end() << " " << a.capacity() << "\n";

    std::cout << "check [] operator \n";
    for(int i = 0 ; i < a.size() ; i++){
        std::cout<<a[i] << " ";
    }
    std::cout << "\n";

    std::cout << "check copy constructor \n";
    Vector<int> b(a);
     std::cout<< "a: " << &a << " " << a.size() << " " << a.begin() << " " << a.end() << " " << a.capacity() << "\n";
     for(int i : a){
        std::cout<<i << " ";
     }
    std::cout << "\n";
    std::cout<< "b: " << &b << " " << b.size() << " " << b.begin() << " " << b.end() << " " << b.capacity() << "\n";
    for(int i : b){
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "change b to check operator = \n";
    b.push_back(14);
    b.push_back(15);
     std::cout<< "b: " << &b << " " << b.size() << " " << b.begin() << " " << b.end() << " " << b.capacity() << "\n";
    for(int i : b){
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "a befor =\n";
     std::cout<< "a: " << &a << " " << a.size() << " " << a.begin() << " " << a.end() << " " << a.capacity() << "\n";
     for(int i : a){
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "a after =\n";
    a = b;
     std::cout<< "a: " << &a << " " << a.size() << " " << a.begin() << " " << a.end() << " " << a.capacity() << "\n";
     for(int i : a){
        std::cout << i << " ";
    }
    std::cout << "\n";
}