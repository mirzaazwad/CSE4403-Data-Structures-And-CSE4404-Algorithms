/*
Find the longest palindromic substring using hashing.
Hint: use binary search to check for all lengths and then traverse accordingly.
The complexity of the algorithm should be O(nlogn).

Test Case #1
Input
cdxyaaabbbbaaazzpqsrt
Output
aaabbbaaa
*/
// In the name of Allah, The Lord of Mercy, The Giver of Mercy
// Author: Mirza Mohammad Azwad
// Institution: Islamic University of Technology
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ll int64_t
#define short int16_t
#define int int32_t
#define ull unsigned long long
#define endl "\n"

using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

namespace Problem
{
    class HashString
    {
    public:
        static const int N = 2000006;
        static const ull hs = 3797;
        ull FF[N], HF[N];
        ull BB[N], HB[N];
        string in;
        int n;

        HashString(string input)
        {
            in = input;
            in = "0" + input;
            generateForwardHash();
            generateBackwardHash();
        }

        ull segF(int x, int y)
        {
            return HF[y] - FF[y - x + 1] * HF[x - 1];
        }

        ull segB(int x, int y)
        {
            return HB[x] - BB[y - x + 1] * HB[y - 1];
        }

        void generateForwardHash()
        {
            FF[0] = 1;
            for (int i = 1; i < N; i++)
                FF[i] = FF[i - 1] * hs; // keeping the powers pre-calculated
            HF[0] = 0;
            n = in.length();
            for (int i = 1; i <= n; i++)
                HF[i] = HF[i - 1] * hs + in[i];
        }

        void generateBackwardHash()
        {
            BB[0] = 1;
            for (int i = N - 1; i > 1; i--)
                BB[i] = BB[i - 1] * hs; // keeping the powers pre-calculated
            HB[0] = 0;
            n = in.length();
            for (int i = n; i >= 0; i--)
                HB[i] = HB[i - 1] * hs + in[i];
        }
    };

    class Program
    {
    private:
        string s;
        HashString *hash1, *hash2;

    public:
        Program(int t = 1)
        {
            for (int i = 1; i <= t; i++)
            {
                takeInput();
                solve();
                clearSpace();
            }
        }

        void takeInput()
        {
            cin >> s;
            string temp = s;
            reverse(temp.begin(), temp.end());
            hash1 = new HashString(s);
            hash2 = new HashString(temp);
            s = "0" + s;
        }

        void clearSpace()
        {
            delete (hash1);
            delete (hash2);
            s.clear();
        }

        bool palindromicSequenceFound(int siz, int n, string &s)
        {
            for (int i = 1; i <= n - siz; i++)
            {
                if (i+siz-1>=i && hash1->segB(i, i + siz - 1) == hash1->segF(i, i + siz - 1))
                {
                    bool found=false;
                    for(int j=0;j<siz;j++){
                        if(s[i+j]!=s[i+siz-j]){
                            found=true;
                        }
                    }
                    if(found && siz<=s.length()){
                        s=s.substr(i,i+siz);
                    }
                }
            }
            return false;
        }

        void solve()
        {
            int low = 1;
            int high = s.length() * 2;
            while (low < high)
            {
                int mid = high + low;
                mid /= 2;
                if (palindromicSequenceFound(mid, s.length(), s))
                {
                    low++;
                    cout << s << endl;
                }
                else
                {
                    high--;
                }
            }
        }
    };
}
signed main()
{
    fastio;
    Problem::Program program = Problem::Program();
    return 0;
}