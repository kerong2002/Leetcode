class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        regex r(R"(\w+)");
        sregex_token_iterator iter(s.begin(), s.end(), r);
        sregex_token_iterator end;
        while (iter != end) {
            v.push_back(*iter);
            ++iter;
        }
        if (pattern.size() != v.size()) {
            return false;
        }
        unordered_map<char, string> um;
        unordered_set<string> used;
        for (int x = 0; x < pattern.size(); ++x) {
            if (um.count(pattern[x])) {
                if (um[pattern[x]] != v[x]) {
                    return false;
                }
            }
            else {
                if (used.count(v[x])) {
                    return false;
                }
                um[pattern[x]] = v[x];
                used.insert(v[x]);
            }
        }
        return true;
    }
};