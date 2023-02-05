class Solution {
public:
    int tribonacci(int n) {
        if(n==0){
            return 0;
        }
        else if(n<=2){
            return 1;
        }
        int f0 = 0;
        int f1 = 1;
        int f2 = 1;
        int save=0;
        for(int x=3;x<=n;x++){
            save=f2;
            f2 += f1 + f0;
            f0 = f1;
            f1 = save;
        }
        return f2;
    }
};