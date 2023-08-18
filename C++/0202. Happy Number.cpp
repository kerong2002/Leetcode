class Solution {
public:
    int sum(int n) {
        int ans = 0;
        while (n) {
            ans += static_cast<int> (pow(n % 10, 2));
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_set<int> us;
        while(true) {
            int s = sum(n);
            if (s == 1) {
                return true;
            }
            if (us.count(s)) {
                return false;
            }
            else {
                us.insert(s);
            }
            n = s;
        }

    }
};