

int removeDuplicates(int* nums, int numsSize){
    int count=1;
    int check=nums[0];
    for(int x=1;x<numsSize;x++){
        if(check==nums[x]){
            continue;
        }
        else{
            nums[count]=nums[x];
            check=nums[x];
            count+=1;
        }
    }
    return count;
}