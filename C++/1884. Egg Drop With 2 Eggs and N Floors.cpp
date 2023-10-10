class Solution {
public:
    int twoEggDrop(int n) {
        double ans = ceil((-1 + sqrt(1 + 8 * n)) / 2);
        return ans;
    }
};