#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

string characters[]={" ",".,/?","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void printKeypad(int num,string output){
    if(num==0){
        cout<<output<<endl;
        return;
    }
    int res=num%10;
    num=num/10;
    string tmp=characters[res];
    for(auto u:tmp){
        printKeypad(num,u+output);
    }
}

int main()
{
    fastio;
    int num;
    cin>>num;
    printKeypad(num,"");
    return 0;
}