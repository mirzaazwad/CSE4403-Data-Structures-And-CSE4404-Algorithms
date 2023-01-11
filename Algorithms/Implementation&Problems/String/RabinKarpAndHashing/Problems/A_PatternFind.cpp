#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;


/* Following program is a C++ implementation of Rabin Karp
Algorithm given in the CLRS book */
 
// d is the number of characters in the input alphabet
#define d 256
 
/* pat -> pattern
    txt -> text
    q -> A prime number
*/
void search(string pat, string txt,int pat_len,int txt_len, int q)
{
    int M = pat_len;
    int N = txt_len;
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;
 
    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;
 
    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }
    
    vector<int>ans;
    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++) {
 
        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters one by one
        if (p == t) {
            /* Check for characters one by one */
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }
 
            // if p == t and pat[0...M-1] = txt[i, i+1,
            // ...i+M-1]
 
            if (j == M)
                ans.push_back(i+1);
        }
 
        // Calculate hash value for next window of text:
        // Remove leading digit, add trailing digit
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
 
            // We might get negative value of t, converting
            // it to positive
            if (t < 0)
                t = (t + q);
        }
    }
    if(ans.size()==0){
        cout<<"Not Found"<<endl;
    }
    else{
        cout<<ans.size()<<endl;
        for(auto u:ans){
            cout<<u<<" ";
        }
        cout<<endl;
    }
}

int main(void){
    int t;
    cin>>t;
    while(t--){
        
        string a,b;
        cin>>a>>b;
        int len_a=a.length();
        int len_b=b.length();
        search(b,a,len_b,len_a,INT_MAX);
    }
    
}