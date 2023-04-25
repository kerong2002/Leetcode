class Solution {
public:
    string reverseWords(string s) {
        stringstream ss;
        ss << s;
        string ans;
        string a;
        while(ss >> a){
            for(int x=a.size()-1;x>=0;x--){
                ans += a[x];
            }
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};