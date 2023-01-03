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
        if(reachable(n)){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }

    bool reachable(ll n){
        if(n==1)return true;
        else if(n%20==0)return reachable(n/20);
        else if(n%10==0)return reachable(n/10);
        else return false;
    }


};

int main(void){
    int testCase;
    cin>>testCase;
    Solution runner=Solution(testCase);
    return 0;
}