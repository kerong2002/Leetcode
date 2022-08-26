

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    *returnSize = n;
    *returnColumnSizes = (int *)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        (*returnColumnSizes)[i] = n;
    }
    int **output=(int **)calloc(n,sizeof(int*));
    for(int y=0;y<n;y++){
        output[y]=(int *)calloc(n,sizeof(int));
    }
    int start_Y=0,start_X=0;
    int end_Y=n,end_X=n;
    int cnt=1;
    int run=0;
    while(true){
        if(start_Y>=end_Y || start_X>=end_X){
            break;
        }
        switch(run){
            case 0:
                for(int x=start_X;x<end_X;x++){
                    output[start_Y][x]=cnt++;
                }
                start_Y+=1;
                run=1;
                break;
            case 1:
                for(int y=start_Y;y<end_Y;y++){
                    output[y][end_X-1]=cnt++;
                }
                end_X-=1;
                run=2;
                break;
            case 2:
                for(int x=end_X-1;x>=start_X;x--){
                    output[end_Y-1][x]=cnt++;
                }
                end_Y-=1;
                run=3;
                break;
            case 3:
                for(int y=end_Y-1;y>=start_Y;y--){
                    output[y][start_X]=cnt++;
                }
                start_X+=1;
                run=0;
                break;
            default:
                break;
        }
    }
    return output;
}