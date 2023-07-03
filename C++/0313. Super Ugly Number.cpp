typedef pair<unsigned long long int, unsigned  long long int> PII;
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int size = primes.size();
        vector<unsigned long long int> ugly({1});
        vector<int> p(size, 0);
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        for (int x = 0; x < size; ++x) {
            pq.push({ugly[p[x]] * primes[x], x});
        }
        for (int x = 0; x < n - 1; ++x) {
            int cur = pq.top().first;
            ugly.push_back(cur);
            while (!pq.empty() && cur == pq.top().first) {
                int t = pq.top().second;
                pq.pop();
                ++p[t];
                pq.push({ugly[p[t]] * primes[t], t});
            }
        }
        return ugly.back();
    }
};