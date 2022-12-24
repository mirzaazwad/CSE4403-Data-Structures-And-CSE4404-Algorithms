#include<bits/stdc++.h>
using namespace std;


void Merge(int arr[],int start,int mid,int end){
   
    int left_size=mid-start+1;
    int right_size=end-mid;
    //create temporary arrays
    int left[left_size],right[right_size];
    //split to temporary arrays
    //copy the data to temporary array
    for(int i=0;i<left_size;i++){
        left[i]=arr[start+i];
    }
    for(int i=0;i<right_size;i++){
        right[i]=arr[mid+1+i];
    }
     int left_ix(0),right_ix(0),res_ix=start;
    while(left_ix<left_size && right_ix<right_size){
        if(left[left_ix]<=right[right_ix]){
            arr[res_ix]=left[left_ix];
            left_ix++;
        }
        else{
            arr[res_ix]=right[right_ix];
            right_ix++;
        }
        res_ix++;
    }
    //copying the remaining elements of left and right arrays if any
    while(left_ix<left_size){
        arr[res_ix]=left[left_ix];
        left_ix++;
        res_ix++;
    }
    while(right_ix<right_size){
        arr[res_ix]=right[right_ix];
        right_ix++;
        res_ix++;
    }


}

void Merge_Sort(int arr[], int start, int end)
{
    if(start>=end){
        return;
    }
    int mid=(start+end)/2;
    Merge_Sort(arr,start,mid);
    Merge_Sort(arr,mid+1,end);
    Merge(arr,start,mid,end);
}




int main(void){
    int arr[10]={-1,-7,5,4,3,0,8,9,2,-3};
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    Merge_Sort(arr,0,9);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}