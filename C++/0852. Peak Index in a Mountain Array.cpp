class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int L = 0;
        int R = arr.size() - 1;
        int mid = 0;
        while (L < R) {
            cout << L << " , " << R << endl;
            mid = (L + R) / 2;
            if (arr[mid] < arr[mid + 1]) {
                L = mid + 1;
            }
            else {
                R = mid;
            }
        }
        return L;
    }
};