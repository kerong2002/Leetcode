class Solution {
public:
    bool check(const string &str, int left, int right){
        while(left < right){
            if(str[left] != str[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    int minCut(string s) {
        if(s.size()==1){
            return 0;
        }
        vector<int> dp(s.size()+1, 0);
        dp[1] = 1;
        for(int y=2;y<=s.size();y++){
            dp [y] = dp[y-1] + 1;
            for(int x=0;x<y;x++){
                if(check(s, x, y-1)){
                    dp[y] = min(dp[x]+1, dp[y]);
                }
            }
        }
        return dp[s.size()]-1;
    }
};