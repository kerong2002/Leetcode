class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;
        vector<int> ans (2, 0);
        while(l < r){
            if(numbers[l] + numbers[r] > target){
                r -= 1;
            }
            else if(numbers[l] + numbers[r] < target){
                l += 1;
            }
            else if(numbers[l] + numbers[r] == target){
                ans[0] = l + 1;
                ans[1] = r + 1;
                break;
            }
        }
        return ans;
    }
};