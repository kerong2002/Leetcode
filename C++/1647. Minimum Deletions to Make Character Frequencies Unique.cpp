class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> um;
        int del = 0;
        unordered_set<int> us;
        for (char c : s) {
            ++um[c];
        }
        for (auto data : um) {
            int freq = data.second;
            while (freq > 0 && us.find(freq) != us.end()) {
                --freq;
                ++del;
            }
            us.insert(freq);
        }
        return del;
    }
};