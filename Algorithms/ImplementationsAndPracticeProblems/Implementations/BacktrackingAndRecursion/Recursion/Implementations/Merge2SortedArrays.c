#include<stdio.h>

int min(int i,int j){
  if(i<j){
    return i;
  }
  else return j;
}

int main(void){
  int arr[10]={1,3,5,7};
  int arr2[10]={2,4,6,8};
  int arr3[20];
  int i=0;int j=0;
  int count=0;
  while(i<10 && j<10){
    if(arr[i]=='\0' || arr2[j]=='\0')break;
    arr3[count]=min(arr[i],arr2[j]);
    if(arr[i]<=arr2[j]){
      i++;
    }
    else if(arr[i]>arr2[j]){
      j++;
    }
    else{
      i++;
      j++;
    }
    count++;
  }
  printf("i: %d j: %d\n",i,j);
  for(;i<10;i++){
    if(arr[i]=='\0')break;
    arr3[count++]=arr[i];
  }
  for(;j<10;j++){
    if(arr2[j]=='\0')break;
    arr3[count++]=arr2[j];
  }
  for(int i=0;arr3[i]!=0;i++){
    printf("%d",arr3[i]);
  }
  return 0;
}
