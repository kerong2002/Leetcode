class Solution {
public:
    int climbStairs(int n) {
        if(n==1){
            return 1;
        }
        else if(n==2){
            return 2;
        }
        else{
            int f1 = 1;
            int f2 = 2;
            int save = 0;
            for(int x=3;x<=n;x++){
                save = f2;
                f2 += f1;
                f1 = save;
            }
            return f2;
        }
    }
};