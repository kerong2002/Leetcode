class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int> pq;
        int size = 0;
        for (auto v : nums1) {
            pq.push(v);
            ++size;
        }
        for (auto v : nums2) {
            pq.push(v);
            ++size;
        }
        double a1 = 0;
        double a2 = 0;
        int cnt = 0;
        while (cnt <= size / 2) {
            if (cnt == size / 2 - (size % 2 == 0)) {
                a1 = pq.top();
                pq.pop();
                break;
            }
            pq.pop();
            ++cnt;
        }
        
        if (size % 2) {
            return a1;
        }
        a2 = pq.top();

        return (a1 + a2) / 2;
    }
};