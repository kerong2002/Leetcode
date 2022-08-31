

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    for(int y=0;y<matrixSize;y++){
        for(int x=y+1;x<matrixSize;x++){
            int temp=matrix[y][x];
            matrix[y][x]=matrix[x][y];
            matrix[x][y]=temp;
        }
    }
    for(int y=0;y<matrixSize;y++){
        for(int x=0;x<matrixSize/2;x++){
            int temp=matrix[y][x];
            matrix[y][x]=matrix[y][matrixSize-x-1];
            matrix[y][matrixSize-x-1]=temp;
        }
    }
     return;
}