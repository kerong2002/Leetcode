void swap(int *a,int *b){
    if(a==b) return;
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}
void sortColors(int* nums, int numsSize){
    int zero=0;
    for(int x=0;x<numsSize;x++){
        if(nums[x]==0){
            swap(&nums[x],&nums[zero]);
            zero+=1;
        }
    }
    for(int x=zero;x<numsSize;x++){
        if(nums[x]==1){
            swap(&nums[x],&nums[zero]);
            zero+=1;
        }
    }
}