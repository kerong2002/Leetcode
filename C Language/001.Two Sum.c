class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>dicts;
        for(int x=0;x<nums.size();x++)
            dicts[nums[x]]=x;
        for(int x=0;x<nums.size();x++){
            int right =target-nums[x];
            if(dicts.count(right) && dicts[right]!=x){
                return{x,dicts[right]};
            }
        }
        return {};
    }
};