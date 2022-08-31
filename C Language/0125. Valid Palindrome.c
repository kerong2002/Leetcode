

bool isPalindrome(char * s){
    char *list=(char *)malloc((strlen(s)+1) * sizeof(char));
    memset(list,'\0',(strlen(s)+1)* sizeof(char));
    int cnt=0;
    for(int x=0;x<strlen(s);x++){
        if(s[x]>=65 && s[x]<=90){

            list[cnt++]=s[x]+32;
        }
        else if(s[x]>=97 && s[x]<=122){
            list[cnt++]=s[x];
        }
        else if(s[x]>=48 &&s[x]<=57){
            list[cnt++]=s[x];
        }
    }
    if(strlen(list)==1){
        return true;
    }
    for(int x=0;x<strlen(list)/2;x++){
        if(list[x]!=list[strlen(list)-1-x]){
            return false;
        }
    }
    return true;
}