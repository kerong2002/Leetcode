

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int **check=(int **)calloc(matrixSize,sizeof(int *));
    for(int y=0;y<matrixSize;y++){
        check[y]=(int *)calloc(matrixColSize[y],sizeof(int));
    }
    for(int y=0;y<matrixSize;y++){
        for(int x=0;x<matrixColSize[y];x++){
            if(matrix[y][x]==0 && check[y][x]==0){
                for(int yy=0;yy<matrixSize;yy++){
                    if(matrix[yy][x]!=0 && check[yy][x]==0){
                        matrix[yy][x]=0;
                        check[yy][x]=-1;
                    }
                }
                for(int xx=0;xx<matrixColSize[y];xx++){
                    if(matrix[y][xx]!=0 && check[y][xx]==0){
                        matrix[y][xx]=0;
                        check[y][xx]=-1;
                    }
                }
            }
        }
    }
}