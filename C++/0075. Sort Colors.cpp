class Solution {
public:
    void sortColors(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> freq(maxVal + 1, 0);
        for (int x = 0; x < nums.size(); ++x) {
            ++freq[nums[x]];
        }
        int x = 0;
        int pos = 0;
        while (x <= maxVal) {
            if (freq[x]) {
                nums[pos++] = x;
                --freq[x];
            }
            else {
                ++x;
            }
        }
    }
};