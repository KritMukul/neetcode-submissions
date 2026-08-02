class Solution {
public:
    int trap(vector<int>& height) {
        int maxi = 0;
        vector<int> pref(height.size());
        for(int i = 0; i < height.size(); i++) {
            maxi = max(maxi, height[i]);
            pref[i] = maxi;
        }
        maxi = 0;
        vector<int> suff(height.size());
        for(int i = height.size()-1; i >= 0; i--){ 
            maxi = max(maxi, height[i]);
            suff[i] = maxi;
        }
        int ans = 0;
        for(int i = 0; i < height.size(); i++) {
            ans += min(pref[i], suff[i]) - height[i];
        }
        return ans;
    }
};
