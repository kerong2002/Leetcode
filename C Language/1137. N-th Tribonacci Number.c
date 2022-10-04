

int tribonacci(int n){
    if(n<2) return n;
    int f1=0,f2=1,f3=1;
    int fib=0;
    for(int x=2;x<n;x++){
        int save=f1;
        f1=f2;
        f2=f3;
        f3=f1+f2+save;
    }
    return f3;
}