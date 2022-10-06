




#define max(a,b) ((a>=b)?(a):(b));

int dp(int *nums,int size){
    int first=0;
    int second=0;
    int temp=0;
    for(int x=0;x<size;x++){
        temp=first;
        first=second+nums[x];
        second=max(second,temp);
    }
    return max(first,second);
}
int rob(int* nums, int numsSize){
    if(numsSize==0) return 0;
    else if(numsSize==1) return *nums;
    else return max(dp(nums,numsSize-1),dp(nums+1,numsSize-1));
}