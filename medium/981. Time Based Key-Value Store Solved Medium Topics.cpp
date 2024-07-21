//https://leetcode.com/problems/time-based-key-value-store/description/
//Time: o(log n)
//Space: o(m n)
class TimeMap {
    unordered_map<string, vector<pair<int, string>>> values;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        values[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int left = 0, right = values[key].size() - 1;

        string answer = "";
        int bestTimeStamp = 0;
        while (left <= right) {
            int mid = (right + left) / 2;

            if (values[key][mid].first == timestamp) {
                answer = values[key][mid].second;
                break;
            }

            if (values[key][mid].first <= timestamp) {
                if (bestTimeStamp < values[key][mid].first) {
                    bestTimeStamp = values[key][mid].first;
                    answer = values[key][mid].second;
                }
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return answer;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
