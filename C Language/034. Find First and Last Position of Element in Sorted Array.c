/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *result = (int *)calloc(2,sizeof(int));
    *returnSize=2;
    int first=0;
    int second=0;
    if(numsSize==0){
        result[0]=-1;
        result[1]=-1;
    }
    for(int x=0,y=numsSize-1;x<numsSize,y>=0;x++,y--){
        if(nums[x]==target && !first){
            result[0]=x;
            first=1;
        }
        if(nums[y]==target && !second){
            result[1]=y;
            second=1;
        }
        if(!first && x==numsSize-1){
            result[0]=-1;
            result[1]=-1;
        }
    }
    return result;
}