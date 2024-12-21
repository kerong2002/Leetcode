class Solution {
public:
        void dfs(vector<vector<string>>& ans, int y, const int n, vector<int> col, vector<int> tr, vector<int> tl) {
        if (y >= n) {
            vector<string> temp;
            for (int y = 0; y < n; y++) {
                string str;
                for (int x = 0; x < n; x++) {
                    if (col[y] == x) {
                        str += "Q";
                    } 
                    else {
                        str += ".";   
                    }
                }
                temp.push_back(str);
            }
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (col[i] == -1 && tr[y + i] == -1 && tl[y - i + n] == -1) {
                col[i] = y;
                tr[y + i] = 1;
                tl[y - i + n] = 1;
                dfs(ans, y + 1, n, col, tr, tl);
                col[i] = -1;
                tr[y + i] = -1;
                tl[y - i + n] = -1;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> col(n, -1);
        vector<int> top_right(2 * n + 1, -1);
        vector<int> top_left(2 * n + 1, -1);
        dfs(ans, 0, n, col, top_right, top_left);
        return ans;
    }
};