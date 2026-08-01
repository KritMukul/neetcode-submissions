class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n), curr(n, 1);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(j == 0) curr[j] = 1;
                else {
                    curr[j] = curr[j-1] + prev[j];
                }
            }
            prev= curr;
        }
        return curr[n-1];

    }
};
