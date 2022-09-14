

int singleNumber(int* nums, int numsSize){
    int single=0;
    for(int x=0;x<numsSize;x++){
        single^=nums[x];
    }
    return single;
}