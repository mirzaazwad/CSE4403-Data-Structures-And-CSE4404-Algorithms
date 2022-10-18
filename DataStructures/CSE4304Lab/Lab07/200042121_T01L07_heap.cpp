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
 
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 

class MedianFinder{
    private:
    priority_queue<int>min_heap;
    priority_queue<int, vector<int>, greater<int> > max_heap;
    Int n;
    public:

    MedianFinder(){
        n=0;
    }

    void AddNum(Int num){
        n++;
        if(n%2!=0){
            max_heap.push(num);
        }
        else{
            max_heap.push(num);
            min_heap.push(max_heap.top());
            max_heap.pop();

        }
        

        
        
    }

    void printMinHeap(){
        while(!min_heap.empty()){
            cout<<min_heap.top()<<" ";
            min_heap.pop();
        }
    }

    void printMaxHeap(){
        while(!max_heap.empty()){
            cout<<max_heap.top()<<" ";
            max_heap.pop();
        }
    }

    double FindMedian(){
        if(n%2!=0){
            return min_heap.top();
        }
        else{
            return double(max_heap.top()+min_heap.top())/2.00f;
        }
    }



};


signed main()
{
    fastio;
    MedianFinder md;
    md.AddNum(8);
    md.AddNum(9);
    md.AddNum(9);
    md.AddNum(10);
    md.AddNum(11);
    cout<<md.FindMedian()<<endl;
    return 0;
}