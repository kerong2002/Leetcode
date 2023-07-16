class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int cnt = 1;
        for (int x = citations.size() - 1; x >=0; --x) {
            if (cnt <= citations[x]) {
                ++cnt;
            }
        }
        return cnt - 1;
    }
};