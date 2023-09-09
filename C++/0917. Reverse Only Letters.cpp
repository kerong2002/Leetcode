class Solution {
public:
    string reverseOnlyLetters(string s) {
        int R = s.size() - 1;
        int L = 0;
        while (L < R) {
            while (R > L && !(s[R] >='a'  && s[R] <= 'z' || s[R] >= 'A' && s[R] <= 'Z')) {
                --R;
            }
            if (L >= R) {
                break;
            }
            while (L < R && !(s[L] >='a'  && s[L] <= 'z' || s[L] >= 'A' && s[L] <= 'Z')) {
                ++L;
            }
            if (L >= R) {
                break;
            }
            swap(s[R], s[L]);
            --R;
            ++L;
        }
        return s;
    }
};