class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        set<int> st(nums.begin(), nums.end());
        
        int a = *st.begin();
        int cnt = 1, maxi = 1;
        for(auto it : st) {
            if(it == a+1) {
                cnt++;
                maxi = max(maxi, cnt);
                a++;
            }
            else {
                a =it;
                cnt= 1;
            }
        }
        return maxi;
    }
};
