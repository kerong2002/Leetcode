class Solution {
public:
    bool isPalindrome(int x) {
        if(x>=0){
            long int overturn=0;
            int saveN=x;
            while(x){
                overturn=overturn*10+x%10;
                x=x/10;
            }
            if(saveN==overturn)
                return true;
        }
        return false;
        
    }
};