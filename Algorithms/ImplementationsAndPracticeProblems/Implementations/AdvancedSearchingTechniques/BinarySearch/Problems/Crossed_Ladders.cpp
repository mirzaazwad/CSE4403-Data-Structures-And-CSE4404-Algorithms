#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

class Program{
    private:
    double x,y,c;
    double computeForC(double streetWidth){
         double xHeight = sqrt((x*x) - (streetWidth*streetWidth));
        double yHeight = sqrt((y*y) - (streetWidth*streetWidth));
        return ((xHeight*yHeight)/(xHeight+yHeight));
    }
    public:
    Program(int t){
        for(int i=1;i<=t;i++){
            cout<<"Case "<<i<<": ";
            solve();
            cout<<endl;
        }
    }



    void solve(){
        cin>>x>>y>>c;
        double low=0.00, high=min(x,y),streetWidth;
        int count=(int)(1e6);
        //the number of possible 1 shifts to find answer
        while(count--){
            streetWidth=(low+high)/2.00;
            if(computeForC(streetWidth)<=c){
                high=streetWidth;
            }
            else{
                low=streetWidth;
            }
        }
        cout<<fixed<<setprecision(10)<<low;

    }

    
};

int main(void){
    int t;
    cin>>t;
    Program solution=Program(t);
}