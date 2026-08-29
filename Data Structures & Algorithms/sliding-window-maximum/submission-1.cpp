class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        unordered_map<int, int> mpp;
        priority_queue<int> pq;
        int i;
        for(i = 0; i<k-1; i++) {
            mpp[nums[i]]++;
            pq.push(nums[i]);
        }
        i = 0;
        for(int r = k-1; r < nums.size(); r++) {
            mpp[nums[r]]++;
            pq.push(nums[r]);
            ans.push_back(pq.top());
            mpp[nums[i]]--;
            if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
            while(!pq.empty() && !mpp.count(pq.top())) pq.pop();
            i++;
        }
        return ans;
    }
};
