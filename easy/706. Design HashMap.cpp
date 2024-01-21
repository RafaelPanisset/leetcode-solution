//https://leetcode.com/problems/design-hashmap/submissions/1151095527/
//Time: O(n)
//Space: O(n)

class MyHashMap {
public:
    vector<pair<int, int> > values;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        bool exist = false;
        for (int i = 0; i < values.size(); i++) {
            if (values[i].first == key) {
                exist = true;
                values[i].second = value;
            }
        }
        if (!exist) {
            values.push_back({key, value});
        }
    }
    
    int get(int key) {
        for (int i = 0; i < values.size(); i++) {
            if (values[i].first == key) {
                return values[i].second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
         for (int i = 0; i < values.size(); i++) {
            if (values[i].first == key) {
                values[i].first = -1;
                values[i].second = -1;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */