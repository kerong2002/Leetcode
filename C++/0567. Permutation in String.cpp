class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()> s2.size()){
            return false;
        }
        vector<int> cnt(26,0);
        int eng = 0;
        for(int y=0;y<s1.size();y++){
            if(cnt[s1[y]-'a']==0){
                cnt[s1[y]-'a']+=1;
                eng+=1;
            }
            else{
                cnt[s1[y]-'a']+=1;
            }
        }
        for(int y=0;y<s2.size()-s1.size()+1;y++){
            vector<int> check = cnt;
            int check_eng = eng;
            for(int x=y;x<y+s1.size();x++){
                if(check[s2[x]-'a']>0){
                    check[s2[x]-'a']-=1;
                    if(check[s2[x]-'a']==0){
                        check_eng-=1;
                    }
                }
                if(check_eng == 0){
                    return true;
                }
            }
        }
        return false;
    }
};