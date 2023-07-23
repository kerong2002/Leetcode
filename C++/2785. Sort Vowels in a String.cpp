class Solution {
public:
    string sortVowels(string s) {
        vector<int> ans;
        for (auto ss : s) {
            if (ss == 'a' || ss == 'e' || ss == 'i' || ss == 'o' || ss == 'u') {
                ans.push_back(ss);
            }
            else if (ss == 'A' || ss == 'E' || ss == 'I' || ss == 'O' || ss == 'U') {
                ans.push_back(ss);
            }
        }
        sort(ans.begin(), ans.end());
        int cnt = 0;
        for(auto& ss : s) {
            if (ss == 'a' || ss == 'e' || ss == 'i' || ss == 'o' || ss == 'u') {
                ss = ans[cnt++];
            }
            else if (ss == 'A' || ss == 'E' || ss == 'I' || ss == 'O' || ss == 'U') {
                ss = ans[cnt++];
            }
        }
        return s;
    }
};