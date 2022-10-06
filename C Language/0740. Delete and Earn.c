

int deleteAndEarn(int* nums, int numsSize){
    int *list=(int *)calloc(10001,sizeof(int));
    int max=0;
    for(int x=0;x<numsSize;x++){
        list[nums[x]]++;
        if(nums[x]>max){
            max=nums[x];
        }
    }
    for(int x=2;x<=max;x++){
        list[x]=x*list[x]+list[x-2];
        if(list[x-1]>list[x]){
            list[x]=list[x-1];
        }
    }
    return list[max];
}