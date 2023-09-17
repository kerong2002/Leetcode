class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int mod = 1337;
        int phi = 1140;
        int exp = 0;
        
        for (int x = 0; x < b.size(); ++x) {
            exp = (b[x] + exp * 10) % phi;
        }
        if (exp == 0) {
            exp = 1140;
        }
        bitset<12> e(exp);
        int ans = 1;
        for (int x = 12; x >=0; --x) {
            ans = ans * ans % mod;
            if (e[x]) {
                ans = ans * (a % mod) % mod;
            }
        }
        return ans;
    }
};