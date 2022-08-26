
int myAtoi(char * s){
    char list[2000]={'\0'};
    int cnt=0;
    for(int x=0;x<strlen(s);x++){
        if(s[x]==' '||s[x]== '+'){
            continue;
        }
        if(s[x]==45){
            list[cnt++]=s[x];
        }
        else if(s[x]>=48 && s[x]<=57){
           list[cnt++]=s[x];
        }
        else{
            break;
        }
    }
//    printf("%s\n",list);
    long long int answer=atoll(list);
    long long int max=INT_MAX;
    long long int min=INT_MIN;
    if(answer>max){
        return INT_MAX;
    }
    else if(answer<min){
        return INT_MIN;
    }
    else{
        return atoi(s);
    }
}