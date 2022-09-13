#include<bits/stdc++.h>
using namespace std;



 

    void swap(int* a,int* b){
        int temp=*a;
        *a=*b;
        *b=temp;
    }

    void swap(int a,int b){
        int temp=a;
        a=b;
        b=temp;
    }


    int heap[10000006];
    int n;


    void heapify(int heap[], int siz, int i)
    {
        int smallest = i; 
        int left = 2 * i + 1; 
        int right = 2 * i + 2; 
    
        if (left < siz && heap[left] < heap[smallest])smallest = left;
    
        if (right < siz && heap[right] < heap[smallest])smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            heapify(heap, siz, smallest);
        }
    }

    void Build_min_heap(int heap[], int siz)
    {
        n=siz-1;
        int start = (siz / 2) - 1;
        for (int i = start; i >= 0; i--) {
            heapify(heap, siz, i);
        }
    }

    void insertNode(int heap[], int& n, int Key)
    {
        n = n + 1;
        heap[n - 1] = Key;
        heapify(heap, n, n - 1);
    }

    void Min_heap_insert(int value, int heap[]){
        insertNode(heap,n,value);
    }
    
    





    void deleteRoot(int heap[], int& n)
    {
        swap(heap[0],heap[n-1]);
        n = n - 1;
        heapify(heap, n, 0);
    }

    int Heap_Minimum(int heap[]){
        return heap[0];
    }

    int Heap_Extract_Min(int heap[]){
        int temp=heap[0];
        deleteRoot(heap,n);
        return temp;
    }

 



int main(void){
    n=0;
    int i=0;
    int m;
    while(cin>>m,m!=-1){
        heap[i]=m;
        i++;
    }
    Build_min_heap(heap,i);
    for(int i=0;i<=n;i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    Heap_Extract_Min(heap);
    int x;
    while(cin>>x,x!=0){
        switch(x){
            case 1:
            cout<<Heap_Minimum(heap)<<endl;
            for(int i=0;i<=n;i++)cout<<heap[i]<<" ";
            cout<<endl;
            break;
            case 2:
            cout<<Heap_Extract_Min(heap)<<endl;
            for(int i=0;i<=n;i++)cout<<heap[i]<<" ";
            cout<<endl;
            break;
            case 3:
            int y;
            cin>>y;
            Min_heap_insert(y,heap);
            for(int i=0;i<=n;i++)cout<<heap[i]<<" ";
            cout<<endl;
            break;

        }
        cin>>x;
    }


    return 0;
}