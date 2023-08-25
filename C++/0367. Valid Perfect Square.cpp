class Solution {
public:
    bool isPerfectSquare(int num) {
        int a = static_cast<int> (sqrt(num));
        return a * a == num;
    }
};