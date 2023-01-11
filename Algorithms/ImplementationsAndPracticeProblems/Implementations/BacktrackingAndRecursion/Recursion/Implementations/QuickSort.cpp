#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
  int *temp;
  temp=a;
  a=b;
  b=temp;
}

int Partition(int arr[],int start,int end){
  int value=arr[start];
  int count_smaller=0;
  for(int i=start+1;i<=end;i++){
    if(arr[i]<value){
      count_smaller++;
    }
  }
  int finalPos=start+count_smaller;
  swap(arr[start],arr[start+count_smaller]);
  int i=start;
  int j=end;
  while(i<j){
    if(arr[i]<arr[finalPos]){
      i++;
    }
    else if(arr[j]>=arr[finalPos]){
      j--;
    }
    else{
      swap(arr[i],arr[j]);
    }
  }
  return finalPos;

}

void quickSort(int arr[],int start,int end){
  if(start>=end)return;
  int c=Partition(arr,start,end);
  quickSort(arr,start,c-1);
  quickSort(arr,c+1,end);
}


 

int main(void){
  int arr[10]={-3,-7,5,4,2,1,0,-8,-4,12};
  for(int i=0;i<10;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  quickSort(arr,0,9);
  for(int i=0;i<10;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;
}
