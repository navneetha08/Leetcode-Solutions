class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int n = strs.size();

        string ans = "";

        for(int i = 0; i < strs[0].size(); i++) {
            bool isPref = false;
            for(int j=0; j < n;j++) {
                if (i < strs[j].size() && (strs[j][i] == strs[0][i])) {
                    isPref = true;
                }
                else {
                    isPref = false;
                    return ans;
                }
            }
            if (isPref) {
                ans += strs[0][i];
            }
        }
        return ans;
    }
};