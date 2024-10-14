
class TrieNode {
public:
    bool isEnd;
    TrieNode* child[2];
    TrieNode() {
        isEnd = false;
        for (auto& c : child) {
            c = nullptr;
        }
    }
};
class Solution {
    TrieNode* root;
public:
    void addNum(int num) {
        TrieNode* node = root;
        int token = 0;
        for (int i = 31; i >= 0; i--) {
            token = (num >> i) & 1;
            if (!node->child[token]) {
                node->child[token] = new TrieNode();
            }
            node = node->child[token];
        }
    }

    int search(int num) {
        int sum = 0;
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int key = (num >> i) & 1;
            int other = key ? 0 : 1;
            if (!node->child[other]) {
                node = node->child[key];
            }
            else {
                sum += (1 << i);
                node = node->child[other];
            }
        }
        return sum;
    }

    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode();
        for (const auto& n : nums) {
            addNum(n);
        }

        int ans = 0;
        for (const auto& n : nums) {
            ans = max(ans, search(n));
        }

        return ans;
    } 
};

