class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int, int> mpp1, mpp2;

        for(auto it : t) {
            mpp2[it]++;
        }

        int resLen = INT_MAX, have = 0, need = mpp2.size();
        pair<int, int> p = {-1, -1};

        int l = 0;
        for(int r = 0; r < s.length(); r++) {
            mpp1[s[r]]++;
            if(mpp2.count(s[r]) && mpp1[s[r]] == mpp2[s[r]]) {
                have++;
            }

            while(have == need) {
                if(r - l + 1 < resLen) {
                    resLen = r-l+1;
                    p = {l, r};
                }

                mpp1[s[l]]--;
                if(mpp2.count(s[l]) && mpp1[s[l]] < mpp2[s[l]]) have--;
                l++;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(p.first, resLen);
    }
};
