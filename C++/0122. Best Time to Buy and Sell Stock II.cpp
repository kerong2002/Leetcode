class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum=0;
        for(int x=1;x<prices.size();x++){
            if(prices[x]-prices[x-1]>0){
                sum+=prices[x]-prices[x-1];
            }
        }
        return sum;
    }
};