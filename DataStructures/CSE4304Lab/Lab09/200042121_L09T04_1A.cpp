#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;


void search(string needle, string haystack,int needle_len,int haystack_len)
{
    int i, j;
    int needle_hash = 0; // hash value for needle_hash
    unsigned int haystack_hash = 0; // hash value for haystack
    int curr_hash = 1;
    int base=31;
 
    for (i = 0; i < needle_len - 1; i++)
        curr_hash = (curr_hash * base) % mod;
 
    for (i = 0; i < needle_len; i++) {
        needle_hash = (base * needle_hash + needle[i]) % mod;
        haystack_hash = (base * haystack_hash + haystack[i]) % mod;
    }

    for (i = 0; i <= haystack_len - needle_len; i++) {
 
        if (needle_hash == haystack_hash) {

            for (j = 0; j < needle_len; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
 
 
            if (j == needle_len)
                cout<<i<<endl;
                return;
        }
 
        if (i < haystack_len - needle_len) {
            haystack_hash = (base * (haystack_hash - haystack[i] * curr_hash) + haystack[i + needle_len]);
        }
    }
    cout<<-1<<endl;
}

int main(void){
    string haystack;
    string needle;
    cin>>haystack>>needle;
    search(needle, haystack,(int)needle.length(),(int)haystack.length());
}
