class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int *arr = new int[cost.size()];
        arr[0] = cost[0];
        arr[1] = cost[1];
        for(int x=2;x<cost.size();x++){
            arr[x] = min(arr[x-1],arr[x-2]) + cost[x];
        }
        return min(arr[cost.size()-2],arr[cost.size()-1]);
    }
};