//https://leetcode.com/problems/design-hashset/description/
//Time: O(1)
//Space: O(n)
class MyHashSet {
public:
    vector<int> values;
    MyHashSet() {
        
    }
    
    void add(int key) {
        values.push_back(key);
    }
    
    void remove(int key) {
        for (int i = 0; i < values.size(); i++)
            if (values[i] == key)
                values[i] = -1;
    }
    
    bool contains(int key) {
        for (int i = 0; i < values.size(); i++)
            if (values[i] == key)
               return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */