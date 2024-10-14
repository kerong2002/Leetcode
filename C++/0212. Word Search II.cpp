class TrieNode {
public:
    bool isWord;
    TrieNode* child[26];

    TrieNode() {
        isWord = false;
        for (auto& c : child) {
            c = nullptr;
        }
    }
};

class Solution {
    int row;
    int col;
    TrieNode* root;
public:
    void addWord(string word) {
        TrieNode* node = root;
        for (char& c : word) {
            int i = c - 'a';
            if (!node->child[i]) {
                node->child[i] = new TrieNode();
            }
            node = node->child[i];
        }
        node->isWord = true;
    }

    void dfs(const vector<vector<char>>& board, int y, int x, TrieNode* node, string word, vector<vector<bool>>& visit, vector<string>& ans) {
        if (x < 0 || y < 0 || x >= col || y >= row || visit[y][x] == true) {
            return;
        }

        char c = board[y][x];
        int token = c - 'a';

        node = node->child[token];

        if (!node) {
            return;
        }

        word += board[y][x];

        if (node->isWord) {
            ans.push_back(word);
            node->isWord = false;  // Mark the word as found
        }

       
        visit[y][x] = true;
        dfs(board, y - 1, x    , node, word, visit, ans);
        dfs(board, y    , x + 1, node, word, visit, ans);
        dfs(board, y + 1, x    , node, word, visit, ans);
        dfs(board, y    , x - 1, node, word, visit, ans);
        visit[y][x] = false;
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        row = board.size();
        col = board[0].size();

        root = new TrieNode();

        for (string& str : words) {
            addWord(str);
        }
        
        string key;
        vector<vector<bool>> visit(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                dfs(board, i, j, root, key, visit, ans);
            }
        }

        return ans;
    }
};