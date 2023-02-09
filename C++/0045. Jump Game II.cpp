class Solution {
public:
    int jump(vector<int>& nums) {
        int step=0;
        int cur=0;
        int last=0;
        for(int x=0;x<nums.size()-1;x++){
            cur = max(cur, x+nums[x]);
            if(last == x){
                step++;
                last = cur;
            }
        }
        return step;
    }
};