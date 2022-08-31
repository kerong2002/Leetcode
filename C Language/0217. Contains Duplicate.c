#define SWAP(x,y) {int temp;temp=x;x=y;y=temp;}
void quickSort(int list[],int left,int right){
    if(left<right){
        int s=list[(left+right)/2];
        int i=left-1;
        int j=right+1;
        while(1){
            while(list[++i]<s);
            while(list[--j]>s);
            if(i>=j)
                break;
            SWAP(list[i],list[j]);
        }
        quickSort(list,left,i-1);
        quickSort(list,j+1,right);
    }
}
bool containsDuplicate(int* nums, int numsSize){
    quickSort(nums,0,numsSize-1);
    for(int x=0;x<numsSize-1;x++){
        if(nums[x]==nums[x+1]){
            return true;
        }
    }
    return false;
}