class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int take = round(double(purchaseAmount) / 10);
        return 100 - take * 10;
    }
};