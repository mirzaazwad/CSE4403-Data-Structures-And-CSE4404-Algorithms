/*
Problem Statement:
Given 2 numbers a and b. Find their GCD.
Constraints:
0<a<40,000
0<b<10^250
Time: 2s
Note: Input very large so be careful.
Test Case #1:
Input: 978 89798763754892653453379597352537489494736
Output: 6
Test Case #2:
Input: 1221 1234567891011121314151617181920212223242526272829
Output: 3
*/
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int ModBigInt(string s,int a){
	int len=s.length();
	int num=0;
	for(int i=0;i<len;i++){
		num=((num%a)*(10%a))%a+(s[i]-'0')%a;// (a*b)%c = (a%c * b%c)%c and (a+b)%c = a%c + b%c
	}
	return num;
}

int main()
{
    fastio;
    int a;string tmp;
	cin>>a>>tmp;
	int b=ModBigInt(tmp,a);
	cout<<__gcd(a,b)<<endl;
    return 0;
}
