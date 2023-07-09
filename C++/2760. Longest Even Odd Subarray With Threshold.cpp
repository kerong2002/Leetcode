class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int maxL = 0;
        for (int L = 0; L < nums.size(); ++L) {
            if (nums[L] % 2) {
                continue;
            }
            else if (nums[L] <= threshold) {
                int SIZE = 1;
                int R = L + 1;
                while (R < nums.size()) {
                    if (nums[R] % 2 == nums[R - 1] % 2 || nums[R] > threshold) {
                        --R;
                        break;
                    }
                    else {
                        ++R;
                    }
                }
                if (R == nums.size()) {
                    R -= 1;
                }
                maxL = max({maxL, SIZE, R - L + 1});
            }
        }
        return maxL;
    }
};