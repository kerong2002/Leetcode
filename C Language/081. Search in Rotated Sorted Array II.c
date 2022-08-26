
int cmp(const void *a,const void *b){
    return (*(int *)a-*(int *)b);
}
bool search(int* nums, int numsSize, int target){
    qsort(nums,numsSize,sizeof(int),cmp);
    return bsearch(&target,nums,numsSize,sizeof(int),cmp);
}