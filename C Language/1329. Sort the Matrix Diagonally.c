

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a,const void *b){
    return (*(int *)a-*(int *)b);
}
int max(int a,int b){
    return ((a>=b)?a:b);
}
int** diagonalSort(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes){
    *returnSize=matSize;
    *returnColumnSizes=(int *)malloc(matSize*sizeof(int));
    for(int y=0;y<matSize;y++){
        (*returnColumnSizes)[y] = * matColSize;
    }
    int offset=max(matSize,matColSize[0]);
    int *put=(int *)calloc(offset*2+1,sizeof(int));
    int **list=(int **)calloc(offset*2+2,sizeof(int *));
    for(int y=0;y<=offset*2+1;y++){
        list[y]=(int *)calloc(offset,sizeof(int));
    }
    for(int y=0;y<matSize;y++){
        for(int x=0;x<matColSize[y];x++){
            list[y-x+offset][put[y-x+offset]]=mat[y][x];
            put[y-x+offset]++;
        }
    }
    for(int y=1;y<=offset*2+1;y++){
         qsort(list[y],offset,sizeof(int),cmp);
    }
    for(int y=0;y<offset*2+1;y++){
        put[y]=offset-1;
    }
    for(int y=matSize-1;y>=0;y--){
        for(int x=matColSize[y]-1;x>=0;x--){
            mat[y][x]=list[y-x+offset][put[y-x+offset]];
            put[y-x+offset]--;
        }
    }
    return mat;
}