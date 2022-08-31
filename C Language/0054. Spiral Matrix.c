

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    *returnSize=matrixSize * matrixColSize[0];
    int *output=(int *)calloc(matrixSize * matrixColSize[0],sizeof(int));
    int start_Y=0,start_X=0;
    int end_Y=matrixSize,end_X=matrixColSize[0];
    int cnt=0;
    int run=0;
    while(true){
        if(start_Y>=end_Y || start_X>=end_X){
            break;
        }
        switch(run){
            case 0:
                for(int x=start_X;x<end_X;x++){
                    output[cnt++]=matrix[start_Y][x];
                }
                start_Y+=1;
                run=1;
                break;
            case 1:
                for(int y=start_Y;y<end_Y;y++){
                    output[cnt++]=matrix[y][end_X-1];
                }
                end_X-=1;
                run=2;
                break;
            case 2:
                for(int x=end_X-1;x>=start_X;x--){
                    output[cnt++]=matrix[end_Y-1][x];
                }
                end_Y-=1;
                run=3;
                break;
            case 3:
                for(int y=end_Y-1;y>=start_Y;y--){
                    output[cnt++]=matrix[y][start_X];
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