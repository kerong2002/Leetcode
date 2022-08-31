

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int row[10][10]={0};
    int column[10][10]={0};
    int martix[10][10]={0};
    int cnt=0;
    for(int y=0;y<boardSize;y++){
        for(int x=0;x<boardSize;x++){
            if(y%3==0 &&x==0 && y!=0){
                cnt+=3;
            }
            if(board[y][x]!='.'){
                if(martix[cnt+x/3][board[y][x]-'0']==0){
                    martix[cnt+x/3][board[y][x]-'0']=1;
                }
                else{
                    return false;
                }
                if(row[y][board[y][x]-'0']==0){
                    row[y][board[y][x]-'0']=1;
                }
                else{
                    return false;
                }
                if(column[x][board[y][x]-'0']==0){
                    column[x][board[y][x]-'0']=1;
                }
                else{
                    return false;
                }
            }
        }
    }
    return true;
}