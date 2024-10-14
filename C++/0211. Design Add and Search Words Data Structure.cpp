class TrieNode {
public:
    TrieNode* child[26];
    bool isWord;
    TrieNode() {
        isWord = false;
        for (auto& c : child) {
            c = nullptr;
        }
    }
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
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
    
    bool help(const string& word, int pos, TrieNode* node) {
        if (pos == word.size()) {
            return node->isWord;
        }
        char c = word[pos];
        int token = c - 'a';
        if (c != '.') {
            return node -> child[token] != nullptr && help(word, pos + 1, node->child[token]);
        }
        for (int i = 0; i < 26; i++) {
            if (node->child[i] != nullptr && help(word, pos + 1, node->child[i])) {
                return true;
            }
        }
        return false;
    }

    bool search(string word) {
       return help(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */