class Solution {
public:
    int totalMoney(int n) {
        int sum = 0;
        for (int x = 0; x < n / 7; ++x) {
            sum += (2 * x + 8) * 7 / 2;
        }
        sum +=  ((n / 7 + 1) +  (n / 7 + n % 7)) * (n % 7) / 2;
        return sum;

    }
};