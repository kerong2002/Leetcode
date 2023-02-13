class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        vector<int> right(n,0);
        vector<int> left(n,0);
        int r = 0;
        int l = 0;
        for(int x=0;x<n;x++){
            r = max(r, height[x]);
            l = max(l, height[n-x-1]);
            right[x] = height[x] >= r ? 0 : r - height[x];
            left[n-x-1]  = height[n-x-1] >= l  ? 0 : l - height[n-x-1];
        }
        int ans = 0;
        for(int x=0;x<n;x++){
            ans += min(left[x],right[x]);
        }
        return ans;
    }
};