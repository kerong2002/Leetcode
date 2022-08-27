

char * convertToTitle(int columnNumber){
    char *answer=(char *)calloc(11,sizeof(char));
    int cnt=0;
    while (columnNumber> 0) {
        if(columnNumber%26==0){
            answer[cnt++] = 'Z';
            columnNumber=columnNumber/26-1;
        }
        else{
            answer[cnt++]=columnNumber%26+'A'-1;
            columnNumber/=26;
        }
    }
    char *rev=(char *)calloc(cnt+1,sizeof(char));
    int run=0;
    for(int x=cnt-1;x>=0;x--){
        rev[run++]=answer[x];
    }
    return rev;
}