
class TrieNode {
public:
    TrieNode* child[2];
    TrieNode() {
        for (auto& c : child) {
            c = nullptr;
        }
    }
};

bool cmp(vector<int>&a, vector<int>& b) {
    return a[1] < b[1];
}

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

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        root = new TrieNode();
        
        vector<int> ans(queries.size(), -1);

        for (int i = 0; i < queries.size(); i++) {
            queries[i].push_back(i);
        }

        sort(nums.begin(), nums.end());
        sort(queries.begin(), queries.end(), cmp);

        int pos = 0;
        for (int i = 0; i < queries.size(); i++) {
            while (pos < nums.size() && nums[pos] <= queries[i][1]) {
                addNum(nums[pos]);
                pos += 1;
            }
            cout << "yes";
            if (pos != 0) {
                ans[queries[i][2]] = search(queries[i][0]);
            }
        }


        return ans;
    }
};