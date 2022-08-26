void reverse(char input[],char rev[]){
    int count=0;
    for(int x=strlen(input)-1;x>=0;x--){
        rev[count]=input[x];
        count+=1;
    }
}
char first[210]={'\0'};
char second[210]={'\0'};
char R_first[210]={'\0'};
char R_second[210]={'\0'};
int answer[5000][300];
char output[5000]={'\0'};
char zero[2]={'0'};
char * multiply(char * num1, char * num2){
    strcpy(first,num1);
    strcpy(second,num2);
    if(strlen(first)==1 && first[0]=='0'||strlen(second)==1 && second[0]=='0'){
        return zero;
    }
    memset(output,'\0',5000*sizeof(char));
    memset(answer,-1,5000*300*sizeof(int));
    reverse(first,R_first);
    reverse(second,R_second);
    for(int y=0;y<strlen(R_second);y++){//乘數挑選
        int carry=0;
        for(int x=0;x<=strlen(R_first);x++){//被乘數挑選
            if(x==strlen(R_first)){
                if(carry==0){
                    break;
                }
                answer[y][y+x]=carry;
                break;
            }
            int s_int,f_int;
            if(R_second[y]>='0'){
                s_int=R_second[y]-'0';
            }
            if(R_first[x]>='0'){
                f_int=R_first[x]-'0';
            }
            if(s_int*f_int+carry>=10){
                answer[y][y+x]=(s_int*f_int+carry)%10;
                carry=(s_int*f_int+carry)/10;
            }
            else{
                answer[y][y+x]=(s_int*f_int+carry)%10;
                carry=0;
            }
        }
    }
    int total[5000]={0};
    for(int y=0;y<strlen(R_second);y++){
        for(int x=0;x<=strlen(R_second)-1+strlen(R_first);x++){
            if(answer[y][x]!=-1){
                total[x]+=answer[y][x];
            }
            if(total[x]>=10){
                total[x+1]+=total[x]/10;
                total[x]%=10;
            }
        }
    }
    int ok=0;
    int out_cnt=0;
    for(int x=strlen(R_second)-1+strlen(R_first);x>=0;x--){
        if(total[x]!=0){
            ok=1;
        }
        if(ok==1){
            output[out_cnt]=total[x]+'0';
            out_cnt+=1;
        }
    }
    memset(first,'\0',210*sizeof(char));
    memset(second,'\0',210*sizeof(char));
    memset(R_first,'\0',210*sizeof(char));
    memset(R_second,'\0',210*sizeof(char));

    return output;
}