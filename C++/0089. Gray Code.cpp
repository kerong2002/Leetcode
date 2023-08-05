class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        int size = 1 << n;
        for (int x = 0; x < size; ++x) {
            int grayCode = (x >> 1) ^ x;
            ans.push_back(grayCode);
        }
        return ans;
    }
};