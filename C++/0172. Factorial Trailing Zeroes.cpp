class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        int temp=5;
        while(n>=temp){
            ans += n/temp;
            temp *=5;
        }
        return ans;
    }
};