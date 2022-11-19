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
