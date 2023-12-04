class Solution {
public:
    string largestGoodInteger(string num) {
        string ans;
        int max_number = -1;
        for (int y = 0; y < num.size() - 2; ++y) {
            bool same = true;
            for (int x = y + 1; x <= y + 2; ++x) {
                if (num[x] != num[y]) {
                    same = false;
                }
            }
            if (same) {
                max_number = max(max_number, num[y] - '0');
            }
        }
        if (max_number >= 0) {
            for (int x = 0; x < 3; ++x) {
                ans.push_back(max_number + '0');
            }
        }
        return ans;
    }
};