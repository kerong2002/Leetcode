class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_map<int, bool> um;
        int cnt = 1;
        int run = 0;
        while (run < n) {
            if (um.count(k - cnt)) {
                ++cnt;
            }
            else {
                um[cnt++] = true;
                run += 1;
            }
        }
        int sum = 0;
        for (auto& k : um) {
            sum += k.first;
        }
        
        return sum;
        
    }
};