class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int, int> mp;
        for (int x = 0; x < target.size(); ++x) {
            mp[target[x]] += 1;
        }

         
        for (int x = 0; x < arr.size(); ++x) {
            if (mp[arr[x]] == 0) {
                return false;
            }
            else {
                mp[arr[x]] -= 1;
            }
        }

        return true;
    }
};