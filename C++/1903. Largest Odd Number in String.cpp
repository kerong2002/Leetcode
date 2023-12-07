class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        int pos = -1;
        bool take = false;
        for (int x = num.size() - 1; x >=0; --x) {
            if ((num[x] - '0') & 1 ) {
                pos = x;
                break;
            }
        }
        for (int x = 0; x <= pos; ++x) {
            ans.push_back(num[x]);
        }
        return ans;
    }
};