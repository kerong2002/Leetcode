
#define min(a,b) ( (a) >= (b) ? b : a)
int minPathSum(int** grid, int gridSize, int *gridColSize){
    if(gridSize==0 || gridColSize[0]==0){
        return 0;
    }
    for(int y=1;y<gridSize;y++){
        grid[y][0] += grid[y-1][0];
    }
    
    for(int x=1;x<gridColSize[0];x++){
        grid[0][x] += grid[0][x-1];
    }

    for(int y=1;y<gridSize;y++){
        for(int x=1;x<gridColSize[0];x++){
            grid[y][x] += min(grid[y-1][x],grid[y][x-1]);
        }
    }
    return grid[gridSize-1][gridColSize[0]-1];
}