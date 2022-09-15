#include<iostream>
using namespace std;
int N;

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
    int smallest=i;
    int first=2*i;
    int second=2*i+1;
    if(first<=N && heap[first]<heap[smallest]){
        smallest=first;
    }
    if(second<=N && heap[second]<heap[smallest]){
        smallest=second;
    }

    if(smallest!=i){
        swap(heap[i],heap[smallest]);
        heapify(smallest,heap,N);
    }
}

void Build_min_heap(int *heap,int N){
    for(int i=N;i>0;i--){
        heapify(i,heap,N);
    }
}

int Heap_Minimim(int heap[]){
    return heap[1];
}

int Heap_extract_min(int heap[]){
    int temp=heap[1];
    swap(heap[1],heap[N]);
    N--;
    Build_min_heap(heap,N);
    return temp;
}

void Min_heap_insert(int value, int heap[]){
    int temp[(N+1)+1];
    for(int i=1;i<=N;i++){
        temp[i]=heap[i];
    }
    delete[] heap;
    heap=new int[(N+1)+1];
    for(int i=1;i<=N;i++)heap[i]=temp[i];
    heap[N+1]=value;
    N++;
    Build_min_heap(heap,N);
}

void Min_Priority_Queue(int heap[],int id,int value=-1){
        switch(id){
            case 1:
            cout<<Heap_Minimim(heap)<<endl;
            for(int i=1;i<=N;i++)cout<<heap[i]<<" ";
            cout<<endl;
            break;
            case 2:
            cout<<Heap_extract_min(heap)<<endl;
            for(int i=1;i<=N;i++)cout<<heap[i]<<" ";
            cout<<endl;
            break;
            case 3:
            if(value==-1)return;
            Min_heap_insert(value,heap);
            for(int i=1;i<=N;i++)cout<<heap[i]<<" ";
            cout<<endl;
            break;
            default:
            return;
        }
}




int main(void){
    nonstd::DynamicArray<int>arr;
    int n;
    while(cin>>n,n!=-1){
        arr.Push_Back(n);
    }

    N=arr.Size();
    int* heap=new int[N+1];
    for(int i=0;i<N;i++){
        heap[i+1]=arr.Get(i);
    }
    Build_min_heap(heap,N);
    cout<<"Min heap:";
    for(int i=1;i<=N;i++)cout<<heap[i]<<" ";
    cout<<endl;
    while(!(cin>>n).eof()){

        if(n!=3)Min_Priority_Queue(heap,n);
        else {
            int value;
            cin>>value;
            Min_Priority_Queue(heap,n,value);
        }

    }
}