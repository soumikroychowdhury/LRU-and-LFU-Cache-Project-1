#include<bits/stdc++.h>
class LFUCache {
public:
    int cap,size,minFreq;
    unordered_map<int, pair<int, int>> m;
    unordered_map<int, list<int>::iterator> mIter;
    unordered_map<int, list<int>> fm;
    LFUCache(int capacity) {
        cap=capacity,size=0;
    }
    
    int get(int key) {
        if(m.count(key)==0) return -1;
        fm[m[key].second].erase(mIter[key]);
        m[key].second++;
        fm[m[key].second].push_back(key);
        mIter[key]=--fm[m[key].second].end();
        if(fm[minFreq].size()==0) minFreq++;
        return m[key].first;
    }
    
    void put(int key, int value) {
        if(cap<=0) return;
        int storedValue=get(key);
        if(storedValue!=-1)
        {
            m[key].first=value;
            return;
        }
        if(size>=cap )
        {
            m.erase( fm[minFreq].front() );
            mIter.erase( fm[minFreq].front() );
            fm[minFreq].pop_front();
            size--;
        }
        m[key]={value, 1};
        fm[1].push_back(key);
        mIter[key]=--fm[1].end();
        minFreq=1;
        size++;
    }
};