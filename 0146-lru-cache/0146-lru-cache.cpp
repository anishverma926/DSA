class LRUCache {
public:
    vector<pair<int, int>> cache; 
    int n;

    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {

        for(int i = 0; i < cache.size(); i++){
            if(cache[i].first == key){
                int val = cache[i].second;

                pair<int, int> temp = cache[i];
                cache.erase(cache.begin() + i);
                cache.push_back(temp);
                return val;
            } 
        }

        return -1;
    }
    
    void put(int key, int value) {
        // case - 1 : if already exist then update value of key
        for(int i = 0; i < cache.size(); i++){
            if(cache[i].first == key){
                cache.erase(cache.begin() + i);
                cache.push_back({key, value});
                return;
            }
        }

        // case - 2 : size == n
        if(cache.size() == n){
            cache.erase(cache.begin());
            cache.push_back({key, value});
        }
        else{
            cache.push_back({key, value});
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */