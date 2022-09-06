

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int put = 0;
void permutation(int *nums,bool *check,int numsSize,int cnt,int *array,int **answer){
    if(cnt==numsSize){
        for(int x=0;x<numsSize;x++){
            answer[put][x] = array[x];
        }
        put += 1;
        return;
    }
    else{
        for(int x=0;x<numsSize;x++){
            if(check[x]==false){
                array[cnt] = nums[x];
                check[x] = true;
                permutation(nums,check,numsSize,cnt+1,array,answer);
                check[x] = false;
            }
        }
    }
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    put=0;
    bool *check = (bool *)calloc(numsSize,sizeof(bool));
    int *array=(int *)calloc(numsSize,sizeof(int));
    int size=1;
    for(int x=1;x<=numsSize;x++){
        size *= x;
    }
    *returnSize=size;
    int **answer = (int **)calloc(size,sizeof(int *));
    *returnColumnSizes = (int *)malloc(size*sizeof(int));
    for(int y=0;y<size;y++){
        answer[y] = (int *)calloc(numsSize,sizeof(int));
        (*returnColumnSizes)[y] = numsSize;
    }
    permutation(nums,check,numsSize,0,array,answer);
    return answer;
}