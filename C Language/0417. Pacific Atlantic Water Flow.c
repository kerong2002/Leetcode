

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes){
    bool **A_visit=(bool **)calloc(heightsSize,sizeof(bool *));
    bool **P_visit=(bool **)calloc(heightsSize,sizeof(bool *));
    for(int y=0;y<heightsSize;y++){
        A_visit[y]=(bool *)calloc(heightsColSize[y],sizeof(bool));
        P_visit[y]=(bool *)calloc(heightsColSize[y],sizeof(bool));
    }
    for(int x=0;x<heightsColSize[0];x++){
        dfs(heights,heightsColSize[0],heightsSize,x,0,P_visit);
    }
    for(int x=0;x<heightsColSize[0];x++){
        dfs(heights,heightsColSize[0],heightsSize,x,heightsSize-1,A_visit);
    }
    for(int y=1;y<heightsSize;y++){
        dfs(heights,heightsColSize[0],heightsSize,0,y,P_visit);
    }
    for(int y=heightsSize-2;y>=0;y--){
        dfs(heights,heightsColSize[0],heightsSize,heightsColSize[0]-1,y,A_visit);
    }
   *returnSize=0;
    for(int y=0;y<heightsSize;y++){
        for(int x=0;x<heightsColSize[0];x++){
            if(P_visit[y][x]&&A_visit[y][x]){
                *returnSize+=1;
            }
        }
    }
     *returnColumnSizes =(int *)malloc((*returnSize)*sizeof(int));
    int **answer=(int **)calloc(*returnSize,sizeof(int *));
    for(int y=0;y<*returnSize;y++){
        answer[y]=calloc(2,sizeof(int));
        (*returnColumnSizes)[y]=2;
    }
    int cnt=0;
    for(int y=0;y<heightsSize;y++){
        for(int x=0;x<heightsColSize[0];x++){
            if(P_visit[y][x]&&A_visit[y][x]){
                answer[cnt][0]=y;
                answer[cnt][1]=x;
                cnt++;
            }
        }
    }
    return answer;
}
void dfs(int **map,int column,int row,int x,int y,bool **check){
    check[y][x]=true;
    if(y<row-1 && check[y+1][x]==false && map[y+1][x]>=map[y][x]){
        dfs(map,column,row,x,y+1,check);
    }
    if(x<column-1 && check[y][x+1]==false && map[y][x+1]>=map[y][x]){
        dfs(map,column,row,x+1,y,check);
    }
    if(y>0 && check[y-1][x]==false && map[y-1][x]>=map[y][x]){
        dfs(map,column,row,x,y-1,check);
    }
    if(x>0 && check[y][x-1]==false && map[y][x-1]>=map[y][x]){
        dfs(map,column,row,x-1,y,check);
    }
}
