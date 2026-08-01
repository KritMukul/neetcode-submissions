class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int ho) {
        int l = 1, h = *max_element(piles.begin(), piles.end());

        while(l < h) {
            int m = l + (h-l)/2;

            int t = 0;
            for(auto it : piles) {
                t += (it + m-1)/m;
                if(t > ho) break;
            }
            if(t > ho) l = m+1;
            else h = m;
        }
        return h;
    }
};
