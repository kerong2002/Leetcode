class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles >= numExchange) {
            int temp = numBottles / numExchange;
            ans += temp;
            numBottles %= numExchange;
            numBottles += temp;
        }
        return ans;
    }
};