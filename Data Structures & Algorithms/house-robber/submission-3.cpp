class Solution {
public:
    int rob(vector<int>& nums) {
        // if(nums.size() <2) return *max_element(nums.begin(), nums.end());
        int curr, prev = 0, prev2 = 0;

        for(int i = 0; i < nums.size(); i++) {
            curr = max(nums[i] + prev2, prev);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
