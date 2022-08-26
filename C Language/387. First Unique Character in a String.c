

int firstUniqChar(char * s){
    int english[26]={0};
    for(int x=0;x<strlen(s);x++){
        english[s[x]-'a']+=1;
    }
    for(int x=0;x<strlen(s);x++){
        if(english[s[x]-'a']==1){
            return x;
        }
    }
    return -1;
}