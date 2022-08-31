

bool canConstruct(char * ransomNote, char * magazine){
    int r_list[26]={0};
    int m_list[26]={0};
    for(int x=0;x<strlen(ransomNote);x++){
        r_list[ransomNote[x]-'a']+=1;
    }
    for(int x=0;x<strlen(magazine);x++){
        m_list[magazine[x]-'a']+=1;
    }
    for(int x=0;x<26;x++){
        if(r_list[x]-m_list[x]>0){
            return false;
        }
    }
    return true;
}