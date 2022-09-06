

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int put=0;
void permutation(int *nums,int numsSize,int cnt,bool *check,int *array,int **answer){
    if(cnt==numsSize){
        for(int x=0;x<numsSize;x++){
            answer[put][x]=array[x];
        }
        put+=1;
        return;
    }
    else{
        for(int x=0;x<numsSize;x++){
            if(x>0 && nums[x] == nums[x-1] && !check[x - 1])
                continue; 
            if(check[x]==false){
                array[cnt]=nums[x];
                check[x]=true;
                permutation(nums,numsSize,cnt+1,check,array,answer);
                check[x]=false;
            }
        }   
    }
}
int cmp(const void *a,const void *b){
    return (*(int *)a-*(int *)b);
}
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    put=0;
    qsort(nums,numsSize,sizeof(int),cmp);
    bool *check=(bool *)calloc(numsSize,sizeof(bool));
    int *array=(int *)calloc(numsSize,sizeof(int));
    *returnSize=1;
    for(int x=1;x<=numsSize;x++){
        *returnSize*=x;
    }
    int **answer=(int **)calloc((*returnSize),sizeof(int *));
    for(int y=0;y<(*returnSize);y++){
        answer[y]=(int *)calloc(numsSize,sizeof(int));
    }
    permutation(nums,numsSize,0,check,array,answer);
    if(put!=(*returnSize)){
        (*returnSize)=put;
        int **new_answer=(int **)calloc(put,sizeof(int*));
        *returnColumnSizes=(int *)malloc(put*sizeof(int));
        for(int y=0;y<put;y++){
            new_answer[y]=(int *)calloc(numsSize,sizeof(int));
            (*returnColumnSizes)[y]=numsSize;
            for(int x=0;x<numsSize;x++){
                new_answer[y][x]=answer[y][x];
            }
            free(answer[y]);
        }
        free(answer);
        return new_answer;
    }
    else{
        *returnColumnSizes=(int *)malloc((*returnSize)*sizeof(int));
        for(int y=0;y<(*returnSize);y++){
            (*returnColumnSizes)[y]=numsSize;
        }
        return answer;
    }
}