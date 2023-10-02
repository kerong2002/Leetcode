class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0;
        int b = 0;
        for (int x = 1; x < colors.size() - 1; ++x) {
            if (colors[x - 1] == 'A' && colors[x] == 'A' && colors[x + 1] == 'A') {
                ++a;
            }
            if (colors[x - 1] == 'B' && colors[x] == 'B' && colors[x + 1] == 'B') {
                ++b;
            }
        }
        return a > b ? true : false;
    }
};