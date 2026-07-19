class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev = 0, prev2 = 0, curr;
        for(int i = 2; i <= cost.size(); i++) {
            curr = INT_MAX;
            curr = min({curr, prev + cost[i-1], prev2 + cost[i-2]});
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
};
