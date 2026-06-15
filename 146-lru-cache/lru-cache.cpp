class LRUCache {
public:
    list<int>dl;
    map<int,pair<int,list<int>::iterator>>mp;
    int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;// agr vaalue hai hi nhi

 // agr hai to usko least recently used bnao
        int value=mp[key].first;
        dl.erase(mp[key].second);
        dl.push_back(key);
        mp[key].second= prev(dl.end());
        return value;
    }
    
    void put(int key, int value) {
       if(mp.find(key)!=mp.end()){ //vo value phalse se hai usko update krna hai or least 
            dl.erase(mp[key].second);
            dl.push_back(key);
            mp[key].second=prev(dl.end());
            mp[key].first=value;
            return;
        }

        if(n==dl.size()){
            int key = dl.front();
            dl.pop_front();
            mp.erase(key);
        }

        dl.push_back(key);
        mp[key]= {value,prev(dl.end())};
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */