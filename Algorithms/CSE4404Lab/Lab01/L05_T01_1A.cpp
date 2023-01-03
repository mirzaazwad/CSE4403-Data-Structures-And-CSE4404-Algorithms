#include<iostream>
#include<vector>
using namespace std;

int main(void){
  int n;
  cin>>n;
  vector<vector<int>>v;
  for(int i=0;i<n;i++){
    vector<int>temp(n);
    for(int j=0;j<n;j++){
      cin>>temp[j];
    }
    v.push_back(temp);
  }
  vector<int>celebrities;
  vector<bool>isCelebrity(n,false);
  for(int i=0;i<n;i++){
    vector<int>peopleKnown;
    for(int j=0;j<n;j++){
      if(v[i][j]){
        peopleKnown.push_back(j);
        if(i==0)isCelebrity[j]=isCelebrity[j]|true;
        else isCelebrity[j]=isCelebrity[j]&true;
      }
      else{
        isCelebrity[j]=isCelebrity[j]&false;
      }
    }
    if(peopleKnown.size()==1 && peopleKnown.front()==i){
      celebrities.push_back(i);
    }
  }
  if(celebrities.size()==1 && isCelebrity[celebrities.front()]){
    cout<<"Person "<<celebrities.front()<<" is the celebrity";
  }
  else{
    cout<<"There is no celebrity."<<endl;
  }
}