class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        if (str2.size() > str1.size()) {
            return false;
        }
        int min_pos = 0;
        for (int x = 0; x < str2.size(); ++x) {
            while (min_pos < str1.size()) {
                int a1 = str1[min_pos] - 'a';
                int a2 = str2[x] - 'a';
                if (a1 == a2) {
                    str2[x] = ' ';
                    break;
                }
                else if ((a1 + 1) % 26 == a2) {
                   str2[x] = ' ';
                    break;
                }
                else {
                     ++min_pos;
                }
            }   
        }

        for (int x = 0; x < str2.size(); ++x) {
            if (str2[x] != ' ') {
                return false;
            }
        }
        return true;
    }
};