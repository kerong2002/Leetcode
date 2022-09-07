

int titleToNumber(char * columnTitle){
    long long int answer=0;
    long long int bonus=1;
    for(int x=strlen(columnTitle)-1;x>=0;x--){
        answer+=bonus*(columnTitle[x]-'A'+1);
        bonus*=26;
    }
    return answer;
}