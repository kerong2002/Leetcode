int change(char N){
    switch(N){
        case 'I'return 1; 
        case 'V'return 5; 
        case 'X'return 10;
        case 'L'return 50;
        case 'C'return 100;
        case 'D'return 500;
        case 'M'return 1000;
    }
    return 0;
}

int romanToInt(char s[]) {
    int size=strlen(s);
    int sum=0;
    if(s==0)return 0;
    sum = change(s[size-1]);  
    for(int x=size-1;x0;x--){
        if(change(s[x-1]) = change(s[x])){
            sum=sum+change(s[x-1]);
        }
        else{
            sum=sum-change(s[x-1]);
        }
    }
    return sum;
}