
int binary_search(int *nums,int low,int high,int target){
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            return mid;
        }
        else{
            if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
    }
    return -1;
}
int search(int* nums, int numsSize, int target){
    return binary_search(nums,0,numsSize-1,target);
}