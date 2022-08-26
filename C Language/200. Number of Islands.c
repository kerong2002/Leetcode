int y_max=0;
int x_max=0;
void floodfill(char **grid,int y,int x){
    grid[y][x]='0';
    if(x>0 && grid[y][x-1]=='1'){
        floodfill(grid,y,x-1);
    }
    if(y>0 && grid[y-1][x]=='1'){
        floodfill(grid,y-1,x);
    }
    if(x<x_max-1 && grid[y][x+1]=='1'){
        floodfill(grid,y,x+1);
    }
    if(y<y_max-1 && grid[y+1][x]=='1'){
        floodfill(grid,y+1,x);
    }
}
int numIslands(char** grid, int gridSize, int* gridColSize){
    y_max=gridSize;
    x_max=gridColSize[0];
    int count=0;
    for(int y=0;y<gridSize;y++){
        for(int x=0;x<gridColSize[y];x++){
            if(grid[y][x]=='0'){
                continue;
            }
            if(grid[y][x]=='1'){
                floodfill(grid,y,x);
                count+=1;
            }
        }
    }
    return count;
}