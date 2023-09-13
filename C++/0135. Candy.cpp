class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        vector<int> candy(size, 1);
        for (int x = 1; x < size; ++x) {
            if (ratings[x] > ratings[x - 1]) {
                candy[x] = candy[x - 1] + 1;
            }
        }
        for (int x = size - 2; x >= 0; --x) {
            if (ratings[x] > ratings[x + 1]) {
                candy[x] = max(candy[x + 1] + 1, candy[x]);
            }
        }
        int ans = 0;
        for (auto x : candy) {
            ans += x;
        }
        return ans;
    }
};