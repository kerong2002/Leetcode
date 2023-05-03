class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int x=0;x<32;x++){
            ans += n%2;
            n = n >> 1;
            if(x==31){
                break;
            }
            ans = ans << 1;
        }
        return ans;
    }
};