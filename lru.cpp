#include<bits/stdc++.h>
class LRUCache {
public:
    int capacity;
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> m;
    LRUCache(int capacity) :capacity(capacity){
        
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        l.splice(l.begin(),l,m[key]);
        return m[key]->second;
    }
    
    void put(int key, int value) {
        if(get(key)!=-1){
            m[key]->second=value;
            return;
        }
        if(m.size()==capacity){
            int x=l.back().first;
            l.pop_back();
            m.erase(x);
        }
        l.emplace_front(key,value);
        m[key]=l.begin();
    }
};