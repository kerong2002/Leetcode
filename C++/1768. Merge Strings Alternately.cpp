class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int s1 = 0;
        int s2 = 0;
        while(s1 < word1.size() || s2 < word2.size()){
            if(s1 < word1.size()){
                ans += word1[s1++];
            }
            if(s2 < word2.size()){
                ans += word2[s2++];
            }
        }
        return ans;
    }
};