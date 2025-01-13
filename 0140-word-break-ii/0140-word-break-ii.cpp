class Solution {
public:

    void recurse(string s, unordered_set<string> dict, int i, vector<string> &res, string &currWord, vector<bool> dp) {
        if (i < 0 || i >= s.size()) {
            res.push_back(currWord);
            currWord = "";
            return;
        }
        string word =""; string temp;
        for(int j=i;j<s.size();j++) {

            word += s[j];

            if (dict.find(word) != dict.end()) {
                temp = currWord;
                if (currWord != "") {
                   currWord += " "; 
                }
                currWord += word;

                recurse(s, dict, j+1, res, currWord, dp);

                currWord = temp;
            }

        }

        // if (dp[i-1]) {
        // recurse(s, dict, i-1, res, currWord, dp);
        // }




    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length(); 

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
        string currSet;
        vector<string> res;
        recurse(s, dict, 0, res, currSet, dp);
        return res;
        
    }
};