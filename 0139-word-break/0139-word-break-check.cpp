class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.length(); bool res = false;

        vector<bool> dp(n, false); 

        unordered_set<string> dict;

        for(int i=0;i<wordDict.size();i++) {
            dict.insert(wordDict[i]);
        }

        string lastWord;
        lastWord += s[n-1];


        dp[n-1] = (dict.find(lastWord) != dict.end()) ? true: false;

        for(int i=n-2; i>=0;i--) {

                string word;

            for(int j=i;j<n;j++) {
                word += s[j];

                if (dict.find(word) == dict.end()) {
                    continue;
                }

                if (j+1 >= n || dp[j+1]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];

        
    }
};