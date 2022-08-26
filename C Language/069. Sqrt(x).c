

int mySqrt(int x){
    int low=0;
    int high=x/2+1;
    while(low<=high){
        long mid=low+(high-low)/2;
        long ans=mid*mid;
        if(x==ans){
            return (int) mid;
        }
        else if(ans>x){
            high=(int)mid-1;
        }
        else{
            low=(int)mid+1;
        }
    }
    return high;
}