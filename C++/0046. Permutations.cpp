class Solution {
public:
    void recursive(vector<vector<int>>& ans, vector<int>& buffer, vector<int> used, int max_size, vector<int>& nums){
        if(buffer.size() >= max_size){
            ans.push_back(buffer);
            return;
        }
        else{
            for(int x=0;x<max_size;x++){
                if(used[x] == 0){
                    buffer.push_back(nums[x]);
                    used[x] = 1;
                    recursive(ans, buffer, used, max_size, nums);
                    buffer.pop_back();
                    used[x] = 0;
                }
            }
        }
    } 
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> buffer;
        vector<int> used(nums.size(), 0);
        recursive(ans, buffer, used, nums.size(), nums);
        return ans;
    }
};