class Solution {
public:
    void combination(vector<vector<int>> &ans, vector<int> &temp, int n, int k, int run){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        else{
            for(int x=run;x<=n;x++){
                temp.push_back(x);
                combination(ans, temp, n, k, x+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        combination(ans, temp, n, k, 1);
        return ans;
    }
};