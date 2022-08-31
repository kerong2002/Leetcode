

int search(int* nums, int numsSize, int target){
    int found=-1;
    for(int x=0;x<numsSize;x++){
        if(nums[x]==target){
            found=x;
            break;
        }
    }
    return found;
}