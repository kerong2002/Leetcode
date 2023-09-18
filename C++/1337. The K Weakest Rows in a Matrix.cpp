class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int size = mat[0].size();
        vector<int> ans;  
        vector<vector<int>> s(size + 1);
        for (int y = 0; y < mat.size(); ++y) {
            int temp = 0;
            for (int x = 0; x < mat[0].size(); ++x) {
                if (mat[y][x]) {
                    ++temp;
                }
            }
            s[temp].push_back(y);
        }
        int cnt = 0;
        int pt = 0;
        while (cnt < k && pt <= mat[0].size()) {
            if (s[pt].size() == 0) {
                ++pt;
            }
            else {
                bool jump = false;
                for (int x = 0; x < s[pt].size(); ++x) {
                    if (cnt < k) {
                        ++cnt;
                        ans.push_back(s[pt][x]);
                    }
                    else {
                        jump = true;
                        break;
                    }
                }
                if (jump) {
                    break;
                }
                else {
                    ++pt;
                }
            }
        }
        return ans;
    }
};