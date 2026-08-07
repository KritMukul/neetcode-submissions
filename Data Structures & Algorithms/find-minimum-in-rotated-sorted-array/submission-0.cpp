class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1, m;
        while(l <= r) {
            int m = l + (r-l)/2;
            if(nums[m] < nums[r]) r = m;
            else if(nums[m] > nums[r]) l = m+1;
            else return nums[m];
            // cout<<l<<" "<<m<<" "<<r<<endl;
        }
        return nums[m];
    }
};
