class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int size = s.size();
        
        string prefix = s.substr(0, size - 1);
        string postfix = s.substr(1, size - 1);

        return (postfix + prefix).find(s) != string::npos;
    }
};