

bool isAnagram(char * s, char * t){
    if(strlen(s)!=strlen(t)){
        return false;
    }
    int *list=(int *)calloc(26,sizeof(int));
    for(int x=0;x<strlen(s);x++){
        list[s[x]-'a']+=1;
        list[t[x]-'a']-=1;
    }
    for(int x=0;x<26;x++){
        if(list[x]!=0){
            return false;
        }
    }
    return true;
}