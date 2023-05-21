class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int gap = arr[1] - arr[0];
        for (int x = 2; x < arr.size(); ++x) {
            if(arr[x] - arr[x-1] != gap) {
                return false;
            } 
        }
        return true;
    }
};