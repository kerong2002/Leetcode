

int maxSubArray(int* nums, int numsSize){
    int max=INT_MIN;
    int sum=0; 
    for(int x=0;x<numsSize;x++){
        sum+=nums[x];
        if(max<sum){
            max=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return max;
    
}