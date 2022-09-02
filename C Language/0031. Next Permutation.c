
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int cmp(const void *a,const void *b){
    return (*(int *)a-*(int *)b);
}
void nextPermutation(int* nums, int numsSize){
    int done=0;
    for(int x=numsSize-1;x>=1;x--){                     //尋找右邊大於左邊的位置
        int compare=0;
        int change_position=0;
        if(nums[x-1]<nums[x]){
            done=1;
            compare=nums[x-1];                          //置換點
            int small_num=INT_MAX;
            for(int right=numsSize-1;right>=x;right--){ //往右尋找比置換點大的最小數字
                if(nums[right]<small_num && nums[right]>compare){
                    small_num=nums[right];
                    change_position=right;              //右邊交換點
                }
            }
            swap(&nums[x-1],&nums[change_position]);    //交換
            for(int rev=x,cnt=0;rev<(x+numsSize)/2;rev++,cnt++){
                swap(&nums[rev],&nums[numsSize-cnt-1]);  //翻轉
            }
            break;
        }
    }
    if(done==0){
        qsort(nums,numsSize,sizeof(int),cmp);
    }
}