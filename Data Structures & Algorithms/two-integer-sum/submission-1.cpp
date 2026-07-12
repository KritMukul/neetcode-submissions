class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> mpp;
        for(int i= 0; i < nums.size(); i++) mpp[nums[i]].push_back(i);

        for(auto it : mpp) {
            if(target == it.first*2) return {it.second[0], it.second[1]};
            if(mpp.count(target - it.first)) {
                if(it.second[0] < mpp[target-it.first][0]) return {it.second[0], mpp[target-it.first][0]};
                return {mpp[target - it.first][0], it.second[0]};
            }
        }
        return {};
    }
};
