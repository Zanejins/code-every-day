class Solution {
public:
    string LCS(string s1, string s2) {
        if(s1.empty() || s2.empty()) return "-1";
        int dp[s1.size()+1][s2.size()+1];
        for(int i = 0; i <= s1.size(); i++)
            dp[i][0] = 0;
        for(int j = 0; j <= s2.size(); j++)
            dp[0][j] = 0;
        for(int i = 1; i <= s1.size(); i++) {
            for(int j = 1; j <= s2.size(); j++)
                dp[i][j] = (s1[i-1] == s2[j-1]) ? dp[i-1][j-1] + 1: max(dp[i-1][j], dp[i][j-1]);
        }
        string res = "";
        for(int i = s1.size(), j = s2.size(); dp[i][j] >= 1;) {
            if(s1[i-1] == s2[j-1]) {
                res += s1[i-1];
                i--;j--;
            }
            else if(dp[i-1][j] >= dp[i][j-1]) i--;
            else j--;
        }
        reverse(res.begin(), res.end());
        return res.empty() ? "-1" : res;
    }
};
