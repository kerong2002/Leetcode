class Solution {
public:
    int max_size = 1;
    int prime[5000];
    void pick(){
        prime[0]=2;
        for(int x=3;x<sqrt(INT_MAX);x++){
            int found=0;
            for(int y=0;y<max_size;y++){
                if(x%prime[y]==0){
                    found=1;
                    break;
                }
                if(found!=1 && y==max_size-1){
                    prime[max_size]=x;
                    max_size++;
                }
            }
        }
    }
    vector<vector<int>> findPrimePairs(int n) {
        pick();
        vector<vector<int>> ans;
        for (int x = 0; x < max_size; ++x) {
            if (n <= prime[x]) {
                
                break;
            }
            if (n - prime[x] >= 2) {
                for (int y = x; y < max_size; ++y) {
                    if (n - prime[x] < prime[y]) {
                        break;
                    }
                    if (n - prime[x] == prime[y]) {
                        ans.push_back({prime[x], prime[y]});
                    }
                }
            }
        }
        return ans;
    }
};