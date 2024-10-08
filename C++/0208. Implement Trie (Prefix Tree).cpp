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

class Trie {
    TrieNode* root;
public:
    Trie() {
       root = new TrieNode;
    }
    
    void insert(string word) {
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
    
    bool search(string word) {
        TrieNode* node = root;
        for (char& c : word) {
            int i = c - 'a';
            if (!node->child[i]) {
                return false;
            }
            node = node->child[i];
        }
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char& c : prefix) {
            int i = c - 'a';
            if (node->child[i] == nullptr) {
                return false;
            }
            node = node->child[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */