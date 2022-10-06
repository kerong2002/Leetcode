
int max(int a,int b){
    return ((a>=b)?a:b);
}

int rob(int* nums, int numsSize){
    if(numsSize==0) return 0;
    if(numsSize==1) return nums[0];
    if(numsSize==2) return max(nums[0],nums[1]);
    int *list=(int *)calloc(numsSize,sizeof(int));
    list[0]=nums[0];
    list[1]=nums[1];
    for(int x=2;x<numsSize;x++){
        list[x]=max(max(nums[x]+list[x-2],list[x-1]),nums[x]+list[x-1]-nums[x-1]);
    }
    return list[numsSize-1];
}