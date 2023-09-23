class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) {
            return "0";
        }
        string ans = "";
        while (n) {
            ans = ((n & 1) ? "1" : "0") + ans;
            n = -(n >> 1);
        }
        return ans;
    }
};