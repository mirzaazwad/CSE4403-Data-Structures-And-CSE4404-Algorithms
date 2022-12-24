#include<bits/stdc++.h>
using namespace std;

int returnSubsequences(string input,string output[]){
    if(input.empty()){
      output[0]="";
      return 1;
    }
    string smallInput=input.substr(1);
    int smallInputSize=returnSubsequences(smallInput,output);
    for(int i=0;i<smallInputSize;i++){
      output[i+smallInputSize]=output[i]+input[0];
    }
    return 2*smallInputSize;
}


int main(void){
  string *output=new string[1000];
  string input;
  cin>>input;
  int count=returnSubsequences(input,output);
  for(int i=0;i<count;i++){
    cout<<output[i]<<endl;
  }
  return 0;
}
