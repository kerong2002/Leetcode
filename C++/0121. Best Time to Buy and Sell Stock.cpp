class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int ans = 0;
        for(int x=1;x<prices.size();x++){
            result += prices[x]-prices[x-1];
            ans = max(ans, result);
            if(result <0){
                result =0;
            }
        }
        return ans;
    }
};