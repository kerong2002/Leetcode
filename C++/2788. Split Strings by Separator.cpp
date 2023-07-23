class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        for (int y = 0; y < words.size(); ++y) {
            string temp;
            for(int x = 0; x < words[y].size(); ++x) {
                if (words[y][x] != separator) {
                    temp += words[y][x];
                }
                else {
                    if(temp.size() != 0) {
                        ans.push_back(temp);
                        temp = "";
                    }
                }
            }
            if(temp.size()) {
                ans.push_back(temp);
            }
        }
        return ans;
    }
};