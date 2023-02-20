class Solution {
public:
    int maxArea(vector<int>& height) {
        int right = 0;
        int left = height.size()-1;
        int area = 0;
        while(right < left){
            area = max(area, min(height[right], height[left]) * (left - right));
            height[right] >= height[left] ? left-- : right++; 
        }
        return area;
    }
};