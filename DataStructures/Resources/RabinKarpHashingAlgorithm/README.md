# Rabin Karp Algorithm

### The basic idea of rabin karp involves three key ideas:
* Rolling Hash Function
* Rabin Karp Finger Print
* Dealing with spurious hits

Rolling Hash Function essentially is the idea that the next windows value can be calculated by subtracting the largest power of window as in the powered base multiplied to the left most character of the window followed by multiplying the current hash value for the window after subtraction with the base and adding the next character. By this logic, the window moves to the next segment.

The second is the Rabin Karp Finger Print, which in and of itself deals with spurious hits. Spurious hits are basically segments that have the same value if a base wasn't considered as we do in the Rabin Karp algorithm. Spurious hits results in what we know as the hashing collision. The rolling hash function upon considering the base deals with most of the hashing collision although not perfectly. The Rabin Karp Finger Print essentially is the base powers we take to deal with this situation.

The first algorithm is a basic version with the assumption that two segments upon considering base won't have the same hash value generated.

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

const int N = 2000006;
const ull hs = 3797;

ull F[N], H[N];
char in[N];
int n;

ull seg(int x, int y) {
    return H[y] - F[y - x + 1] * H[x - 1];
}


int main()
{
    F[0] = 1; for(int i = 1; i < N; i++) F[i] = F[i - 1] * hs; // keeping the powers pre-calculated
    scanf("%s", in + 1); // 1 indexing
    n = strlen(in + 1);


    H[0] = 0;
    for(int i = 1; i <= n; i++)
        H[i] = H[i - 1] * hs + in[i];

    // now there will be qr queries and we need to check if seg[x, y] == seg[l, r]
    int qr;
    scanf("%d", &qr) ;
    while(qr--) {
        int x, y, l, r;
        scanf("%d %d %d %d", &x, &y, &l, &r);
        if(seg(x, y) == seg(l, r)) puts("YES");
        else puts("NO");
    }
    return 0;
}

```

The second version of this algorithm takes into account the cases when the hash value matches but the substring isn't necessarily the same. First we check if the hash value matches and then we check as to whether the substring itself matches.
```cpp

void RabinKarp(string txt, int txt_len, string pat, int pat_len, int base)
{
    unsigned int pat_hash = 0;
    unsigned int txt_hash = 0;
    unsigned int curr_hash = 1;
    for (int i = 0; i < pat_len - 1; i++)
    {
        curr_hash = curr_hash * base;
    }

    for (int i = 0; i < pat_len; i++)
    {
        pat_hash = (base * pat_hash + pat[i]);
        txt_hash = (base * txt_hash + txt[i]);
    }

    for (int i = 0; i <= txt_len - pat_len; i++)
    {
        if (pat_hash == txt_hash)
        {
            int j;
            for (j = 0; j < pat_len; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    break;
                }
            }
            if (j == pat_len)
            {
                cout << i << endl;
                return;
            }
        }

        if (i < txt_len - pat_len)
        {
            txt_hash = (base * (txt_hash - txt[i] * curr_hash) + txt[i + pat_len]);
        }
    }
    cout << "Not Found" << endl;
}

//RabinKarp(txt, txt.length(), pat, pat.length(), 1 << (txt.length())); using
```

* The best case: <b>O(m+n-1)</b>
* The worst case: <b>O(mn)</b>

## References:

* [Abdul Bari Sir's Explanation](https://www.youtube.com/watch?v=qQ8vS2btsxI)
* [Geeks For Geeks](https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/)
* [CP Algorithms](https://cp-algorithms.com/string/rabin-karp.html