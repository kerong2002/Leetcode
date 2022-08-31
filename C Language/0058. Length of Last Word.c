int lengthOfLastWord(char  s){
    char data[99][99]={'0'};
    char  pick=strtok(s, );
    int cnt=0;
    while(pick!=NULL){
        strcpy(data[cnt++],pick);
        pick=strtok(NULL, );
    }
    return strlen(data[cnt-1]);
}