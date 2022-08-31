

int strStr(char * haystack, char * needle){
    //strcat(haystack,needle);
    char *find=strstr(haystack,needle);
    int pick=-1;
    while(find!=NULL){
        pick=find-haystack;
        break;
        return pick;
    }
    return pick;
}