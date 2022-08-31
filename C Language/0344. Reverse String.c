

void reverseString(char* s, int sSize){
    for(int x=0;x<sSize/2;x++){
        char temp=s[x];
        s[x]=s[sSize-1-x];
        s[sSize-1-x]=temp;
    }
}