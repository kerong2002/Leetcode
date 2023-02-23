class Solution {
public:
    bool isSubsequence(string s, string t) {
        int point = 0;
        for(int x=0;x<t.length();x++){
            if(point >= s.length()){
                return true;
            }
            if(t[x]==s[point]){
                point++;
            }
        }
        return point >= s.length() ? true :false;
    }
};