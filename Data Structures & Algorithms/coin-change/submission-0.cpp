class Solution {
public:
    int coinChange(vector<int>& c, int a) {
        int n = c.size();
        vector<int> v(a+1, 1e9);

        for(int i = 0; i <= a; i++) if(i % c[0] == 0) v[i] = i/c[0];

        for(int i = 1; i < n; i++) {
            for(int j = a; j >= 0; j--) {
                int take = INT_MAX;
                int x = 0;
                while(c[i] * ++x <= j) v[j] = min(v[j], x + v[j-x*c[i]]);
                // v[j] = min(v[j], take);
            }
        }
        return v[a] == 1e9 ? -1 : v[a];
    }
};
