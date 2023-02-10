class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_size=0;
        bool done = false;
        for(int y=0;y<s.length();y++){
            vector<bool> check(256,false);
            int sum=0;
            for(int x=y;x<s.length();x++){
                if(check[s[x]]==false){
                    check[s[x]] = true;
                    sum+=1;
                    max_size = max(max_size,sum);
                }
                else{
                    break;
                }
                if(s.length()-y<=max_size){
                    done = true;
                    break;
                }
            }
            if(done){
                break;
            }
        }
        return max_size;
    }
};
