class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> dic;
        
        for (int x = 0; x < nums.size(); ++x) {
            ++dic[nums[x]];
        }

        int maxVal = nums[0];
        for (unordered_map<int, int>::iterator it = dic.begin(); it != dic.end(); ++it) {
            if (it->second > dic[maxVal]) {
                maxVal = it->first;
            }
        }
        return maxVal;
    }
};