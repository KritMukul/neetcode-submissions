class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n), pref(n), suff(n);
        int prod = 1;
        pref[0] = 1;
        suff[n-1] = 1;
        for(int i = 1; i < nums.size(); i++) {
            prod *= nums[i-1];
            pref[i] = prod;
        }
        prod = 1;
        for(int i = n-2; i >= 0; i--) {
            prod *= nums[i+1];
            suff[i] = prod;
        }

        for(int i = 0; i < n; i++) {
            ans[i] = suff[i] * pref[i];
        }
        return ans;
        
    }
};
