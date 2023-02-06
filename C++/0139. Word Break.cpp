class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set(wordDict.begin(),wordDict.end());
        int s_size = s.size();
        vector<bool> dp(s_size+1,false);
        dp[0] = true;
        for(int x=0;x<s_size;x++){
            if(!dp[x]) continue;
            for(int y=x+1;y<=s_size;y++){
                if(word_set.count(s.substr(x,y-x))){
                    dp[y] = true;
                }
            }
        }
        return dp[s_size];
    }
};