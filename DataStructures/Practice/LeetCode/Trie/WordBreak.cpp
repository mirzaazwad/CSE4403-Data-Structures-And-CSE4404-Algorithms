#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int>dp;
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> word_set(wordDict.begin(), wordDict.end());
        dp.resize(s.length()+1);
        fill(dp.begin(), dp.end(), -1);
        return wordBreakRecursion(s, word_set, 0);
    }

    bool wordBreakRecursion(string& s, set<string>& word_set, int start) {
        if (start == s.length()) {
            return true;
        }
        if(dp[start]!=-1){
            return dp[start];
        }
        for (int i = start + 1; i <= s.length(); i++) {
            if (word_set.find(s.substr(start, i - start)) != word_set.end() and
                wordBreakRecursion(s, word_set, i)) {
                dp[start]=true;
                return dp[start];
            }
        }
        dp[start]=false;
        return false;
    }
};

int main(void)
{
    string s;
    cin >> s;
    vector<string> wordDict;
    string t;
    while (cin >> t)
    {
        wordDict.push_back(t);
    }
    Solution solution;
    if (solution.wordBreak(s, wordDict))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}