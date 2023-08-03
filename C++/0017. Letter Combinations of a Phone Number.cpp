class Solution {
public:
    void dfs(vector<string>& ans, vector<string> phone, string temp, const string digits, int cnt) {
        if (cnt == digits.size()) {
            ans.push_back(temp);
            return;
        }
        else {
            string value = phone[digits[cnt] - '0'];
            for(int x = 0; x < value.size(); ++x) {
                temp.push_back(value[x]);
                dfs(ans, phone, temp, digits, cnt + 1);
                temp.pop_back();
            }
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(!digits.size()){
            return ans;
        }
        vector<string> phone = {"", "", "abc",  "def",
                                "ghi",  "jkl",  "mno",
                                "pqrs", "tuv",  "wxyz"};
        
        string temp;
        dfs(ans, phone, temp, digits, 0);
        return ans;
    }
};