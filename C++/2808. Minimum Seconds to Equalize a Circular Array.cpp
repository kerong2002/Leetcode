class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size();
        int ans = n - 1;

        unordered_map<int, vector<int>> m;
        
        for (int x = 0; x < n; ++x) {
            m[nums[x]].push_back(x);
        }
        
        for (auto i : m) {
            vector<int> v = i.second;
            int len = v.size();

            int maxi = (n - 1) - (v[len - 1] - v[0]);
            for (int x = 1; x < len; ++x) {
                maxi = max(maxi, v[x] - v[x - 1] - 1);
            }
            ans = min(ans, maxi);
        }
        return (ans + 1) / 2;
    }
};