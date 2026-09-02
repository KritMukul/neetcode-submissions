class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> st;
        int n = position.size();
        vector<pair<int, int>> v;
        for(int i= 0; i < position.size(); i++) {
            v.emplace_back(position[i], speed[i]);
        }

        sort(v.rbegin(), v.rend());

        for(int i = 0; i < n; i++) {
            if(!st.empty() && st.top() >= (double)(target-v[i].first) / v[i].second) {

            }
            else st.push(((double)target - v[i].first)/ v[i].second);
        }
        return st.size();
    }
};
