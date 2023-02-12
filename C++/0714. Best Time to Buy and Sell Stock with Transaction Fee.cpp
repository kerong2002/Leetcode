class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        const int n = prices.size();
        vector<int> money(n,0);
        vector<int> hold(n,0);
        money[0] = 0;
        hold[0] = -prices[0];
        for(int x=1;x<n;x++){
            money[x] = max(money[x-1], prices[x]+hold[x-1]-fee);
            hold[x] = max(hold[x-1], money[x-1]-prices[x]);
        }
        return money[n-1];
    }
};