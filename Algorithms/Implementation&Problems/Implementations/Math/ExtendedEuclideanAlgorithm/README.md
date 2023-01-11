# Extended Euclidean Algorithm

###### Helpful resources:

> [CP Algorithms](https://cp-algorithms.com/algebra/extended-euclid-algorithm.html) This also contains, practice problems, I would give the solutions in the problems section for this topic

> [GeeksForGeeks](https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/)


> [Wikipedia](https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm) This is just to know about the background and certain applications as in bascially extra tidbits


> [A Brief Mathematical Understanding](http://www-math.ucdenver.edu/~wcherowi/courses/m5410/exeucalg.html)


Extended Euclidean GCD Implementation(C++):

```CPP
#include<bits/stdc++.h>
using namespace std;

pair<pair<int,int>,int>gcd(int a,int b){//first pair is for x and y,and second integer is for gcd in return pair
    static pair<pair<int,int>,int>res;
    if(b==0){
        res.first.first=1;
        res.first.second=0;
        res.second=a;
        return res;
    }
    int x1,y1;
    pair<pair<int,int>,int>d=gcd(b,a%b);
    x1=res.first.first,y1=res.first.second;
    res.first.first=y1;
    res.first.second=x1-y1*(a/b);
    return res;
}

int main(void){
    int a,b;cin>>a>>b;
    int x,y;
    pair<pair<int,int>,int>g=gcd(a,b);
    cout<<g.first.first<<" "<<g.first.second<<" "<<g.second;

}
```

Go through the resources for better understanding. 

