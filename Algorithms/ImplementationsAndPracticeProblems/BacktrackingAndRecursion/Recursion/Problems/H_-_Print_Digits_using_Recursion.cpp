#include<iostream>
#include<vector>
using namespace std;
#define ll long long

class Solution
{
    private:

    ll n;

    public:

    Solution(int t)
    {
        for(int i=0;i<t;i++){
            solve();
        }
    }

    void solve(){
        cin>>n;
        if(n==0){
            cout<<0<<" "<<endl;
            return;
        }
        printDigits(n);
        cout<<endl;
    }

    void printDigits(ll n){
        if(n==0)return;
        else{
            printDigits(n/10);
            cout<<n%10<<" ";
        }
    }


};

int main(void){
    int testCase;
    cin>>testCase;
    Solution runner=Solution(testCase);
    return 0;
}