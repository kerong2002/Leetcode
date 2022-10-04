

int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 1;
    int cnt=2;
    int old_1=1,old_2=1;
    int answer=0;
    while(cnt!=n){
        answer=old_1+old_2;
        old_1=old_2;
        old_2=answer;
        cnt+=1;
    }
    return answer;
}