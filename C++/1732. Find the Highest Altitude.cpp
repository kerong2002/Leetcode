class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int high = 0;
        int n = 0;
        for (auto x : gain) {
            n += x;
            high = max(high, n);
        }
        return high;
    }
};