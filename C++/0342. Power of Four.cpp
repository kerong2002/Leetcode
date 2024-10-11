class Solution {
public:
    bool isPowerOfFour(int n) {
        float x = log(n) / log(4);
        if (n <= 0) {
            return 0;
        }
        else {
            return pow(4, int(x)) == n;
        }
    }
};