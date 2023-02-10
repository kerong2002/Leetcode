class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pos=0;
        int neg=0;
        int ans=0;
        for(int x=0;x<nums.size();x++){
            if(nums[x]==0){
                pos=0;
                neg=0;
            }
            else if(nums[x]<0){
                pos ^= neg;
                neg ^= pos;
                pos ^= neg;
                neg +=1;
                if(pos>0){
                    pos+=1;
                }
            }
            else{
                pos+=1;
                if(neg>0){
                    neg+=1;
                }
            }
            ans = max(ans, pos);
        }
        return ans;
    }
};