class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = 0;
        for (auto x : nums) {
            n = max(n, x);
        }
        vector<int> arr(n + 1, 1);
        arr[n] += 1;
        for (auto x : nums) {
            if(arr[x] <= 0) {
                return false;
            }
            else {
                arr[x] -= 1;
            }
        }
        bool ans = true;
        for (int x = 1; x <= n; ++x) {
            if(arr[x] > 0) {
                ans = false;
            }
        }
        
        return ans;
    }
};