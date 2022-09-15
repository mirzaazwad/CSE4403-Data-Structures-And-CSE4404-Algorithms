#include<iostream>
using namespace std;

namespace nonstd{
    template<typename T>class DynamicArray{
        private:
        int capacity;
        T* array;
        void resize(){
            capacity<<=1;
            T *temp=new T[capacity];
            for(int i=0;i<size;i++)temp[i] = array[i];
            delete[] array;
            array=temp;
        }
        public:
        int size;
        DynamicArray(int n=0){
            size=n;
            capacity=2;
            while(capacity<size){
                capacity<<=1;
            }
            array=new T[capacity];
        }

        T Get(int i){
            if(i<0 || i>=size){
                throw("DynamicArray index out of range");
            }
            return array[i];
        }

        void Set(int i,T value){
            if(i<0 || i>=size){
                throw("DynamicArray index out of range");
            }
            array[i]=value;
        }

        void Push_Back(T value){
            if(size<capacity){
                array[size]=value;
                size++;
            }
            else{
                resize();
                array[size]=value;
                size++;
            }
        }

        int Size(){
            return size;
        }
        
        int Capacity(){
            return capacity;
        }

        void Remove(int i){
            int j;
            for(j=i;j<size-1;j++){
                swap(array[j],array[j+1]);
            }
            array[j]=0;
            size--;
        }
        

    };
}


void heapify(int i,int* heap,int N){
    int largest=i;
    int first=2*i+1;
    int second=2*i+2;
    if(first<N && heap[first]>heap[largest]){
        largest=first;
    }
    if(second<N && heap[second]>heap[largest]){
        largest=second;
    }

    if(largest!=i){
        swap(heap[i],heap[largest]);
        heapify(largest,heap,N);
    }
}

void Build_max_heap(int *heap,int N){
    for(int i=N-1;i>=0;i--){
        heapify(i,heap,N);
    }
}

void heapSort(int *heap,int N){
    for(int i=N;i>0;i--){
        swap(heap[0],heap[i-1]);
        Build_max_heap(heap,i-1);
    }
    for(int i=0;i<N/2;i++){
        swap(heap[i],heap[N-1-i]);
    }
}


int main(void){
    nonstd::DynamicArray<int>arr;
    int n;
    while(cin>>n,n!=-1){
        arr.Push_Back(n);
    }

    int N=arr.Size();
    int* heap=new int[N];
    for(int i=0;i<N;i++){
        heap[i]=arr.Get(i);
    }
    Build_max_heap(heap,N);
    cout<<"Max heap:";
    for(int i=0;i<N;i++)cout<<heap[i]<<" ";
    cout<<endl;
    heapSort(heap,N);
    cout<<"Sorted:";
    for(int i=0;i<N;i++)cout<<heap[i]<<" ";
    cout<<endl;
    delete(heap);
}