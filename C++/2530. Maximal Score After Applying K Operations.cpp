class Solution {
    long long ans;
public:
    void cal(int& k, priority_queue<int> v) {  // 注意：這裡傳值而不是引用
        int n = 0;
        while (k) {
            // cout << v.top() << ' ';
            n = v.top();
            ans += n;
            v.pop();
            v.push(ceil(n / 3.0));
            k--;
        }
        // cout << '\n';
    }

    long long maxKelements(vector<int>& nums, int k) {
        ans = 0;
        priority_queue<int> pq(nums.begin(), nums.end());
        cal(k, pq);

        return ans;
    }
};