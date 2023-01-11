/* Varun and you are talking about a movie that you have recently watched while Sachin is busy teaching Number Theory. Sadly, Sachin caught Varun talking to you and asked him to answer his question in order to save himself from punishment. The question says:
Given two weights of a and b units, in how many different ways you can achieve a weight of d units using only the given weights? Any of the given weights can be used any number of times (including 0 number of times).
Since Varun is not able to answer the question, he asked you to help him otherwise he will get punished.
Note: Two ways are considered different if either the number of times a is used or number of times b is used is different in the two ways.
Input Format:
The first line of input consists of an integer 
T denoting the number of test cases.
Each test case consists of only one line containing three space separated integers a, b and d.
Output Format:
For each test case, print the answer in a separate line.
Constraints:
1 ≤T≤ 10^5
1 ≤ a < b ≤ 10^9
0≤d≤10^9
Sample Input 1
4
2 3 7
4 10 6
6 14 0
2 3 6
Sample Output 1
1
0
1
2
Explanation
Test case 1: 7 can only be achieved by using 2 two times and 3 one time.
Test case 2: 6 can't be achieved by using 4 and 10 .So, 0ways are there. */
#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define ll long long

ll gcd(ll a, ll b, ll& x, ll& y) {
if (b == 0) {
x = 1;
y = 0;
return a;
}
ll x1, y1;
ll d = gcd(b, a % b, x1, y1);
x = y1;
y = x1 - y1 * (a / b);
return d;
}

ll multiplicativemodinverse(ll a, ll m){
    ll B,q;
    ll g = gcd(a,m,B,q);
    return B;
}

ll countways(ll a,ll b, ll c){
    if(c%__gcd(a,b)!=0)return 0;
    ll y1=((c%a)*(multiplicativemodinverse(b,a)))%a;
    if(c/b<y1)return 0;
    return (c/b-y1)/a+1;

}


int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        int a,b,x,y,c;
       cin>>a>>b>>c;   
        cout<<countways(a,b,c)<<endl;
        
    }
    return 0;
}
    
