#include<bits/stdc++.h>
using namespace std;

string characters[]={" ",".,/?","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int FindSubsequences(int num,string output[]){
    if(num==0){
        output[0]="";
        return 1;
    }
    int res=num%10;
    num=num/10;
    int numSize=FindSubsequences(num,output);
    string tmp=characters[res];
    int count=0;
    string temp[numSize];
    for(int i=0;i<numSize;i++){
        temp[i]=output[i];
    }
     for(int i=0;i<numSize;i++){
            for(auto u:tmp){
                output[count++]=temp[i]+u;
            }
        }
    return count;
}

int main(void){
    int num;
    cin>>num;
    string *output=new string[1000];
    int count=FindSubsequences(num,output);
    for(int i=0;i<count;i++){
        cout<<output[i]<<endl;
    }
    delete(output);
    return 0;
}