class Solution {
public:

    string encode(vector<string>& strs) {
        string enc = "";
        for(auto it : strs) {
            enc += to_string(it.length()) + '#';
            enc += it;
        }
        return enc;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for(int i = 0; i < s.length(); ) {
            string t = "";
            while(i < s.length() && s[i] != '#') {
                t += s[i];
                i++;
            }
            int len = stoi(t);
            i++;
            ans.push_back(s.substr(i, len));
            i += len;
        }
        return ans;
    }
};