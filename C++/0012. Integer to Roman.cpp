class Solution {
public:
    string intToRoman(int num) {
        string convert[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int arr[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int size = sizeof(arr) / sizeof(arr[0]);
        string ans;
        for (int y = 0; y < size; ++y) {
            if (num >= arr[y]) {
                for (int x = 0; x < num / arr[y]; ++x) {
                    ans += convert[y];
                }
                num %= arr[y];
            }
        }
        return ans;
    }
};