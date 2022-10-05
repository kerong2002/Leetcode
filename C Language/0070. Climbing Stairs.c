

int climbStairs(int n){
    if(n<3) return n;
    int f1=2,f2=3;
    for(int x=3;x<n;x++){
        int save=f2;
        f2=f1+f2;
        f1=save;
    }
    return f2;
}