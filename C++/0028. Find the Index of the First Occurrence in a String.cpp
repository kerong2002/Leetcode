class Solution {
public:
    int kmp_search(string str, vector<int> next, string search_s){
        int i = 0;  //主字串
        int j = 0;  //子字串
        while(i < str.size()){
            if(str[i] == search_s[j]){
                i += 1;
                j += 1;
            }
            else {
                if (j > 0) {
                    j = next[j - 1];
                }
                else{
                    i++;
                }
            }
            if(j==search_s.size()){
                return i-j;
            }
        }
        return -1;
    }
    void kmp_create_next(vector<int> &next, string search_s){
        int prefix_size = 0;
        int i = 1;
        while(i < search_s.size()){
            if(search_s[prefix_size] == search_s[i]){
                prefix_size++;
                next[i] = prefix_size;
                i++;
            }
            else{
                if(prefix_size == 0){
                    next[i] = 0;
                    i++;
                }
                else{
                    prefix_size = next[prefix_size-1];
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
        vector<int> next(needle.size(), 0);
        kmp_create_next(next, needle);
        return kmp_search(haystack, next, needle);
    }
};