class Solution {
public:
    int climbStairs(int n) {
        int curr  = 1, prev = 0, prev2 = 0;
        while(n--) {
            prev2 = prev;
            prev = curr;
            curr = prev + prev2;
        }
        return curr;

    }
};
