#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

namespace DS{
    template<typename T>class DynamicArray{
        private:
        int capacity;
        T* array;
        void resize(){
            T temp[size];
            for(int i=0;i<size;i++)temp[i] = array[i];
            delete[] array;
            array=new T[capacity];
            for(int i=0;i<size;i++)array[i]=temp[i];
        }
        public:
        int size;
        DynamicArray(){
            size=0;
            capacity=2;
            array=new T[capacity];
        }

        T getelem(int i){
            if(i<0 || i>=size){
                throw("DynamicArray index out of range");
            }
            return array[i];
        }

        void setelem(int i,T value){
            if(i<0 || i>=size){
                throw("DynamicArray index out of range");
            }
            array[i]=value;
        }

        void push_back(T value){
            if(size<capacity){
                array[size]=value;
                size++;
            }
            else{
                capacity<<=1;
                resize();
                array[size]=value;
                size++;
            }
        }
        

    };
}

void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}


void heapify(int arr[], int siz, int i)
{
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 
 
    if (left < siz && arr[left] > arr[largest])largest = left;
 
    if (right < siz && arr[right] > arr[largest])largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, siz, largest);
    }
}

void Build_max_heap(int arr[], int siz)
{
    int start = (siz / 2) - 1;
    for (int i = start; i >= 0; i--) {
        heapify(arr, siz, i);
    }
}

void deleteRoot(int arr[], int& n)
{
    swap<int>(arr[0],arr[n-1]);
    n = n - 1;
    heapify(arr, n, 0);
}

void sortingFunction(int arr[],int n){
    while(n!=0){
        deleteRoot(arr,n);
    }
}

void reverse(int arr[],int n){
    for(int i=0;i<n/2;i++){
        swap<int>(arr[i],arr[n-1-i]);
    }
}





 



int main(void){

    DS::DynamicArray<int>arr=DS::DynamicArray<int>();
    int n;
    while(cin>>n,n!=-1){
        arr.push_back(n);
    }
    n=arr.size;
    int heap[n];
    for(int i=0;i<n;i++){
        heap[i]=arr.getelem(i);
    }
    cout<<"Max heap:";
    Build_max_heap(heap,n);
    for(int i=0;i<n;i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    int sorted[n];
    for(int i=0;i<n;i++){
        sorted[i]=heap[i];
    }

    sortingFunction(sorted,n);
    reverse(sorted,n);
    cout<<"Sorted:";
    for(int i=0;i<n;i++)cout<<sorted[i]<<" ";
    cout<<endl;








    return 0;
}