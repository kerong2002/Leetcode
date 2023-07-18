class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        stack<int> st;
        vector<int> result(size, 0);
        for (int x = 0; x < size; ++x) {
            while (!st.empty() && temperatures[x] > temperatures[st.top()]) {
                result[st.top()] = x - st.top();
                st.pop();
            }
            st.push(x);
        }
        return result;
    }
};