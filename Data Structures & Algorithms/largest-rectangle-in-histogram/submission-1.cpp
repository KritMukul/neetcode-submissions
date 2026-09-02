class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> l(n, 0), r(n, n-1);
        stack<int> st;
        for(int i = 0; i < heights.size(); i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                r[st.top()] = i-1;
                st.pop();
            }
            st.push(i);
        }
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                l[st.top()] = i + 1;
                st.pop();
            }
            st.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, (i - l[i]) * heights[i] + (r[i] - i) * heights[i] + heights[i]);
        }
        return ans;
    }
};
