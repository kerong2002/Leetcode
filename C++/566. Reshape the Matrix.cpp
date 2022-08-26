class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n=mat.size();
        int m=mat[0].size();
        if(m*n!=r*c) return mat;
        vector<vector<int>>answer;
        int translate_r=0;
        int translate_c=0;
        for(int y=0;y<r;y++){
            answer.push_back(vector<int>());
            for(int x=0;x<c;x++){
                answer[y].push_back(mat[translate_r][translate_c]);
                if(++translate_c==m){
                    translate_c=0;
                    translate_r++;
                }
            }
        }
        return answer;
    }
};