class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mpp;

        for(auto it : strs) {
            vector<int> f(26, 0);
            for(auto it2 : it) {
                f[it2 - 'a']++;
            }
            mpp[f].push_back(it);
        }
        vector<vector<string>> ans;
        for(auto it : mpp) {
            ans.push_back(it.second);
        }
        return ans;


    }
};
