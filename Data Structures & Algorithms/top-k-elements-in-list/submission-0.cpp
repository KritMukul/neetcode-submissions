class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(auto it : nums) mpp[it]++;

        priority_queue<pair<int, int>> pq;
        for(auto it:  mpp){ 
            pq.push({it.second, it.first});
        }
        vector<int> ans;
        while(k--) {
            auto x = pq.top();
            pq.pop();
            ans.push_back(x.second);
        }
        return ans;
    }
};
