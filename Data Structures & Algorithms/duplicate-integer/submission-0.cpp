class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mpp;

        for(auto it : nums) {
            if(mpp.count(it)) return true;
            mpp[it] = true;
        }
        return false;
    }
};