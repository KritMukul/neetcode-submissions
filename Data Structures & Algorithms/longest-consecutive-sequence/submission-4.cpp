class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        unordered_set<int> st(nums.begin(), nums.end());
        

        int maxi = 1;
        for(auto it : st) {
            if(st.find(it-1)==st.end()){
                int len = 1;
                while(st.find(it + len) != st.end()) {
                    len++;
                    maxi = max(maxi, len);
                }
            }
            
        }
        return maxi;
    }
};
