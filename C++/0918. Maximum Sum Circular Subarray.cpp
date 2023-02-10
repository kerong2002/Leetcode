class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int big = 0;
        int cur_big = INT_MIN;
        int small = 0;
        int cur_small = INT_MAX;
        int sum = 0;
        for(int x : nums){
            big = max(x, big + x);
            cur_big = max(cur_big, big);
            small = min(x , small + x);
            cur_small = min(cur_small, small);
            sum += x;
        }
        return (sum-cur_small==0) ? cur_big : max(cur_big, sum-cur_small);
    }
};