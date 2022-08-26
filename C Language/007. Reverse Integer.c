

int reverse(int x){
    char list[20]={'\0'};
    char answer[20]={'\0'};
    sprintf(list,"%d",x);
    if(list[0]==45){
        answer[0]='-';
        int cnt=1;
        for(int x=strlen(list)-1;x>=1;x--){
            answer[cnt++]=list[x];
        }
        if(strlen(answer)==11 && strcmp(answer,"-2147483648")>0){
            return 0;
        }
        else{
            return atoi(answer);
        }
    }
    else{
        int cnt=0;
        for(int x=strlen(list)-1;x>=0;x--){
            answer[cnt++]=list[x];
        }
        if(strlen(answer)==10 && strcmp(answer,"2147483647")>0){
            return 0;
        }
        else{
            return atoi(answer);
        }
    }
}
