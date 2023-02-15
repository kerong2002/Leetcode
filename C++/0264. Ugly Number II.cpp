class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(1,1);
        int u2=0, u3=0, u5=0;
        while(dp.size()<n){
            int temp = min(dp[u2]*2,min(dp[u3]*3, dp[u5]*5));
            if(temp==dp[u2]*2){
                u2++;
            }
            if(temp==dp[u3]*3){
                u3++;
            }
            if(temp==dp[u5]*5){
                u5++;
            }
            dp.push_back(temp);
        }
        return dp.back();
    }
};