// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int left = 1;
        long long int right = n;
        long long int mid = 0;
        while(left <= right){
            mid = (left + right)/2;
            if(isBadVersion(mid)){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};