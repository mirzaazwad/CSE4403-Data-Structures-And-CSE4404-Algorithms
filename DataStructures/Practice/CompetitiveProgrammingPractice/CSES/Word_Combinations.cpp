#include <iostream>
using namespace std;

const int md = 1000000007;

int trie[1000005][26];
bool stop[1000005];
int dp[5005];
int ct = 0;

void insert(string s) {
    int node = 0;
    for (int i = 0; i < s.size(); i++) {
        if (!trie[node][s[i]-'a']) trie[node][s[i]-'a'] = ++ct;
        node = trie[node][s[i]-'a'];
    }
    stop[node] = 1;
}


string s;
int search(int x) {
    int node = 0, ans = 0;
    for (int i = x; i < s.size(); i++) {
        if (!trie[node][s[i]-'a']) return ans;
        node = trie[node][s[i] - 'a'];
        if (stop[node]) {
            (ans += dp[i+1])%=md;
        }
    }
    return ans;
}

void solve(){
    cin>>s;
    int k; cin>>k;
    while(k--) {
        string x; cin>>x;
        insert(x);
    }
    dp[s.size()] = 1;
    for (int i = s.size() - 1; i>=0; i--) {        
        dp[i] = search(i);
    }
    cout<<dp[0];
}    
signed main(){
    solve();
}