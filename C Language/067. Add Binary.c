
int max(int a,int b){
    return ((a>=b)?a:b);
}
void reverse(char *list){
    char *new=(char *)calloc(strlen(list)+1,sizeof(char));
    int run=0;
    for(int x=strlen(list)-1;x>=0;x--){
        new[run++]=list[x];
    }
    memset(list,'\0',strlen(list)*sizeof(char));
    strcpy(list,new);
}
char * addBinary(char * a, char * b){
    int big=max(strlen(a),strlen(b));
    char *answer=(char *)calloc(big+2,sizeof(char));
    reverse(a);
    reverse(b);
    int carry=0;
    int cnt=0;
    while(true){
        int a_number=0;
        int b_number=0;
        if(cnt>strlen(a)&&cnt>strlen(b)&&carry==0){
            break;
        }
        if(cnt<strlen(a)){
            if(a[cnt]=='1'){
                a_number=1;
            }
        }
        if(cnt<strlen(b)){
            if(b[cnt]=='1'){
                b_number=1;
            }
        }
        answer[cnt++]=(a_number+b_number+carry)%2+'0';
        carry=(a_number+b_number+carry)/2;
    }
    char *rev=(char *)calloc(strlen(answer)+1,sizeof(char));
    int zero=0;
    for(int x=cnt-1,run=0;x>=0;x--){
        if(answer[x]!='0'){
            zero=1;
        }
        if(zero==1){
            rev[run++]=answer[x];
        }
    }
    if(zero==0){
        rev[0]='0';
    }
    return rev;
}