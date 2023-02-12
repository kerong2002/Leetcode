class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s0 = 0;             //rst
        int s1 = -prices[0];    //buy
        int s2 = INT_MIN;       //sell
        for(int x=1;x<prices.size();x++){
            int pre0 = s0;
            int pre1 = s1;
            int pre2 = s2;
            s0 = max(pre0, pre2);
            s1 = max(pre1, pre0-prices[x]);
            s2 = pre1 + prices[x];
        }
        return max(s0,s2);
    }
};