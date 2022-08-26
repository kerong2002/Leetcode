int searchInsert(int* nums, int numsSize, int target){
    int find=-1;
    for(int x=0;x<numsSize;x++){
        if(nums[x]==target){
            find=x;
            break;
        }
        else if(nums[x]>target){
            find=x;
            break;
        }
    }
    if(find==-1){
        find=numsSize;
    }
    return find;
}