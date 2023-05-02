class Solution {
public:
    void permutation(vector<string> &ans, string &s , string &temp, int x){
        if(x >= s.size()){
            ans.push_back(temp);
            return;
        }
        else{
            temp.push_back(s[x]);
            permutation(ans, s, temp, x+1);
            temp.pop_back();
            if(isalpha(s[x])){
                if(isupper(s[x])){
                    temp.push_back(tolower(s[x]));
                }
                else{
                    temp.push_back(toupper(s[x]));
                }
                permutation(ans, s, temp, x+1);
                temp.pop_back();
            }
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string temp;
        permutation(ans, s, temp, 0);
        return ans;
    }
};