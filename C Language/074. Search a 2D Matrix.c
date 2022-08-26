

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int find=0;
    for(int y=matrixSize-1;y>0;y--){
        if(target>=matrix[y][0]){
            find=y;
            break;
        }
    }
    for(int x=0;x<matrixColSize[find];x++){
        if(target==matrix[find][x]){
            return true;
        }
    }
    return false;
}