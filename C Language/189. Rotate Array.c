


void rotate(int* nums, int numsSize, int k){
    if(numsSize==2){
        if(k%2!=0){
            int temp=nums[0];
            nums[0]=nums[1];
            nums[1]=temp;
        }
    }
    if(numsSize>2){
        k%=numsSize;
        for(int x=0;x<(numsSize-k)/2;x++){
            int temp=nums[x];
            nums[x]=nums[numsSize-k-x-1];
            nums[numsSize-k-x-1]=temp;
        }
        for(int x=0;x<k/2;x++){
            int temp=nums[numsSize-1-x];
            nums[numsSize-1-x]=nums[numsSize-k+x];
            nums[numsSize-k+x]=temp;
        }
        for(int x=0;x<numsSize/2;x++){
            int temp=nums[x];
            nums[x]=nums[numsSize-1-x];
            nums[numsSize-1-x]=temp;
        }
    }
}