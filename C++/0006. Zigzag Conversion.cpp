class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        string *z = new string[numRows];
        for(int x=0;x<s.size();x++){
            if(x%(2*numRows-2) >= numRows){
                z[abs((2*numRows-2)-x%(2*numRows-2))] += s[x];
            }
            else{
                z[x%(2*numRows-2)] += s[x];
            }
        }
        string ans;
        for(int x=0;x<numRows;x++){
           ans += z[x];
        }
        return ans;
    }
};