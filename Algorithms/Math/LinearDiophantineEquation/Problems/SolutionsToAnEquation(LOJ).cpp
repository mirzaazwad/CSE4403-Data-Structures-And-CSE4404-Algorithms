//Problem statement Link: https://lightoj.com/problem/solutions-to-an-equation
#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(long long a, long long b, long long c, long long &x0, long long &y0, long long &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void shift_solution(long long & x, long long & y, long long a, long long b, long long cnt) {
    x += cnt * b;
    y -= cnt * a;
}

long long find_all_solutions(long long a, long long b, long long c, long long minx, long long maxx, long long miny, long long maxy) {
    long long x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    long long sign_a = a > 0 ? +1 : -1;
    long long sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    long long lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    long long rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    long long lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    long long rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    long long lx = max(lx1, lx2);
    long long rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}

int main(void){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        long long A,B,C,minx,maxx,miny,maxy;
        cin>>A>>B>>C>>minx>>maxx>>miny>>maxy;
        C=-C;//reversing the sign of C as Ax+By+C=0 => Ax+By=-C and we are solving for the latter
        cout<<"Case "<<i<<": ";
      //Dealing with edge cases
         if(A==0 && B==0 && C==0) cout<<(maxx-minx+1)*(maxy-miny+1)<<'\n';

        else if(A==0 && B==0) cout<<0<<'\n';

        else if(A==0){
            if(C%B!=0 || miny>C/B || maxy<C/B) cout<<0<<'\n';
            else cout<<(maxx-minx+1)<<'\n';
        }
        else if(B==0){
            if(C%A!=0 || minx>C/A || maxx<C/A) cout<<0<<'\n';
            else cout<<(maxy-miny+1)<<'\n';
        }
      //main case
        else cout<<find_all_solutions(A, B, C, minx,maxx,miny,maxy)<<'\n';
     }
     return 0;
    }
