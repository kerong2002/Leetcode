class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        while (n > 1) {
            int offset = n / 2;
            ans += offset;
            n -= offset;
        }
        return ans;
    }
};