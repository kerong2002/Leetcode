class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        if(nums.size() == 1) {
            return -1;
        }
        if (nums.size() == 2 && nums[1] - nums[0] == 1)  {
            return 2;
        }
        int a = 0;
        int b = 1;
        int max_size = 0;
        int cnt = 2;
        bool change = false;
        if (nums[1] - nums[0] == 1) {
            max_size = 2;
            change = true;
        }
        while (b < nums.size()) {
            if(nums[b] - nums[a] != 1) {
                a+=1;
                b+=1;
                cnt = 2;
                if (b < nums.size() && nums[b] - nums[a] == 1) {
                    max_size = max(max_size, cnt);
                    change = true;
                }
                continue;
            }
            if ((cnt/2) * 2 + a  < nums.size()) {
                if (nums[(cnt/2) * 2 + a] == nums[a]) {
                    cnt += 1;
                    change = true;
                }
                else {
                    a += 1;
                    b += 1;
                    cnt = 2;
                    continue;
                }
            }
            else {
                a += 1;
                b += 1;
                cnt = 2;
                continue;
            }
//            cout << a << "," << b  << ":"<<cnt << endl;
            max_size = max(cnt, max_size);
            if((cnt/2) * 2 + b < nums.size()) {
                if(nums[(cnt/2) * 2 + b] == nums[b]){
                    cnt += 1;
                    change = true;
                }
                else {
                    a += 1;
                    b += 1;
                    cnt = 2;
                    continue;
                }
            }
            else {
                a += 1;
                b += 1;
                cnt = 2;
                continue;
            }
//            cout << a << "," << b  << ":"<<cnt << endl;
            max_size = max(cnt, max_size);
        }
//        cout << max_size << "@";
        if (!change) {
            max_size = -1;
        }
        //cout << max_size;
        return max_size;
    }
};
