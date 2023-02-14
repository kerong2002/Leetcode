class Solution {
public:
    int numDecodings(string s) {
       const int n = s.length();
       vector<int> dp(n+1,0);
       dp[0] = 1;
       for(int x=1;x<=n;x++){
           dp[x] = s[x-1]=='0' ? 0 : dp[x-1];
           if(x>1 && (s[x-2]=='1' || (s[x-2]=='2'&& s[x-1]<='6'))){
               dp[x] += dp[x-2];
           }
       } 
       return dp.back();
    }
};