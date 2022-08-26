

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int **ans=(int **)malloc(numRows*sizeof(int *));
    *returnSize=numRows;
    *returnColumnSizes=(int *)malloc(numRows*sizeof(int));
    for(int y=0;y<numRows;y++){
        ans[y]=(int *)malloc((y+1)*sizeof(int));
        (*returnColumnSizes)[y]=y+1;
        ans[y][0]=ans[y][y]=1;
        for(int x=1;x<y;x++){
            ans[y][x]=ans[y-1][x]+ans[y-1][x-1];
        }
    }
    return ans;
}