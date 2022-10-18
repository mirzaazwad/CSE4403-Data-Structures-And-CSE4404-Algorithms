//In the name of Allah, The Lord of Mercy, The Giver of Mercy
//Author: Mirza Mohammad Azwad
//Institution: Islamic University of Technology
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#define ll int64_t
#define Short int16_t
#define Int int32_t
#define endl "\n"
  
// Header files, namespaces,
// macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
  
 
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 

class MedianFinder{
    private:
    ordered_set mp;
    Int n;
    public:
    MedianFinder(){
        n=0;
        mp.clear();
    }

    void AddNum(Int num){
        n++;
        mp.insert(num);
    }

    double FindMedian(){
        if((n&1)){
            Int pos=(n>>1)+1;
            return *(mp.find_by_order(pos-1));
        }
        else{
            Int pos=(n>>1);
            double sum=(*(mp.find_by_order(pos-1))+*(mp.find_by_order(pos)));
            return sum/2.0f;
        }
    }

};




signed main()
{
    fastio;
    MedianFinder md=MedianFinder();
    md.AddNum(10);
    md.AddNum(12);
    md.AddNum(9);
    cout<<md.FindMedian()<<endl;
    md.AddNum(8);
    cout<<setprecision(1)<<fixed<<md.FindMedian()<<endl;
    return 0;
}