class Solution {
public:
    bool isIsomorphic(string s, string t) {
        bool eng[256] = {false};
        unordered_map<char, char> um;
        for (int x =  0; x < s.size(); ++x) {
            if (um.count(s[x])) {
                if (um[s[x]] != t[x]) {
                    return false;
                }
            }
            else {
                if (eng[t[x]])  {
                    return false;
                }
                else {
                    um[s[x]] = t[x];
                    eng[t[x]] = true;
                }
            }
        }
        return true;
    }
};