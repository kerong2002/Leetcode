
class TrieNode {
public:
    TrieNode* child[26];
    int num;
    TrieNode() {
        num = 0;
        for (auto& c : child) {
            c = nullptr;
        }
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
       root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char& c : word) {
            int i = c - 'a';
            if (!node->child[i]) {
                node->child[i] = new TrieNode();
            }
            node = node->child[i];
            node->num += 1;
        }
    }

    int search(string word) {
        TrieNode* node = root;
        int sum = 0;
        for (char& c : word) {
            int i = c - 'a';
            if (!node->child[i]) {
                return -1;
            }
            node = node->child[i];
            sum += node->num;
        }
        return sum;
    }


};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans(words.size(), 0);
        Trie t;

        for (int i = 0; i < words.size(); i++) {
            t.insert(words[i]);
        }

        for (int i = 0; i < words.size(); i++) {
            ans[i] = t.search(words[i]);
        }
        return ans;
    }
};