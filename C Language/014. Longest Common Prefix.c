

char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0) return "";
    if (strsSize == 1) return strs[0];
    int min=strlen(strs[0]);
    for(int y=1;y<strsSize;y++){
        min=strlen(strs[y])<min?strlen(strs[y]):min;
    }
    char *same=(char *)malloc((min+1)*sizeof(char));
    memset(same,'\0',(min+1)*sizeof(char));
    for(int y=0;y<min;y++){
        int check=y;
        for(int x=0;x<strsSize-1;x++){
            if(strs[x][y]!=strs[x+1][y]){
                check=-1;
                break;
            }
        }
        if(check==-1){
            break;
        }
        if(check==y){
            same[check]=strs[0][y];
        }
    }
    return same;
}