class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0;
        int score = values[0];
        for(int y=1;y<values.size();y++){
            ans = max(ans, values[y]-y+score);
            score = max(score, values[y]+y);
        }
        return ans;
    }
};