class LRUCache {
public:
    list<int>dl;
    unordered_map<int,pair<int,list<int>::iterator>>mp;
    int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;// agr vaalue hai hi nhi

 // agr hai to usko least recently used bnao
        int value=mp[key].first; 
        dl.erase(mp[key].second); // delte kro us node ko or usko least recently bnao
        dl.push_back(key);// jo least recently hoga vo list ke last me hoga
        mp[key].second= prev(dl.end());
        return value;
    }
    
    void put(int key, int value) {
       if(mp.find(key)!=mp.end()){ //vo value phalse se hai usko update krna hai or least 
            dl.erase(mp[key].second); // recently bnana hai
            dl.push_back(key);
            mp[key].second=prev(dl.end());// prev list ke last element ka adress de raha
            mp[key].first=value; // value update ki 
            return;
        }

        if(n==dl.size()){
            int oldkey = dl.front(); //hmara size ki capecity puri ho gyi isliye last
            dl.pop_front(); // jo sbse km use hua hai use dlete krkenge . or vo hai list
            mp.erase(oldkey);// ke start me  lekin list se delete krne se phale uski key
        }// store krayenge kuki us key coorseponding entry mp me se bhi to delete krni 
        // isiliye list me hmne key stor kiya hai
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