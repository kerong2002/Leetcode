class Solution {
public:
    void search(const string s, int left, int right, int &begin, int &end){
        while(left>=0 && right<s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        if(end < right - left - 1){
            begin = left + 1;
            end = right - left - 1;
        }
    }
    string longestPalindrome(string s) {
        if(s.length()<2) return s;
        int max_size = s.length();
        int begin = 0, end = 0;
        for(int x=0;x<s.length()-1;x++){
            search(s, x, x+1, begin, end);
            search(s, x, x  , begin, end);
        }
        return s.substr(begin, end);
    }
};