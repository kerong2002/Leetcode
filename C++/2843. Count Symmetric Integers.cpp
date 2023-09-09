class Solution {
public:
    bool cal(string a) {
        if (a.size() % 2 == 0) {
            int mid = a.size() / 2;
            int s = 0;
            int e = 0;
            for (int x = 0; x < a.size(); ++x) {
                if (x >= mid) {
                    s += a[x] - 'a';
                }
                else {
                    e += a[x] - 'a';
                }
            }
            return s == e ? true : false;
        }
        else {
            return false;
        }
    }
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int x = low; x <= high; ++x) {
            if (cal(to_string(x))) {
                ++ans;
            }
        }
        return ans;
    }
};