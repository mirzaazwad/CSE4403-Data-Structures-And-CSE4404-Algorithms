#include<iostream>
using namespace std;

namespace nonstd{

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

    template<typename T>class MaxHeap{//creating max heap with my approach
        private:
        DynamicArray<T>heap;
        int n;
        public:
        MaxHeap(){
            DynamicArray<T>heap=DynamicArray<T>();
            n=0;
        }

        void insertDirect(T value){//not using heapify
            heap.push_back(value);
            n=heap.size;
            int index=n-1;
            int ix=n-1;
            while(ix>0){
                if(heap.getelem(ix)<heap.getelem(index)){
                    T temp=heap.getelem(index);
                    heap.setelem(index,heap.getelem(ix));
                    heap.setelem(ix,temp);
                    index=ix;
                }
                ix/=2;
            }
            if(heap.getelem(ix)<heap.getelem(index)){
                    T temp=heap.getelem(index);
                    heap.setelem(index,heap.getelem(ix));
                    heap.setelem(ix,temp);
                    index=ix;
            }

        }

        void heapify(){
            for(int i=n-1;i>=0;i--){
                int ix=i;
                while(2*ix+1<n && 2*ix+2<n){
                        int firstChildIx=2*ix+1;
                        int secondChildIx=2*ix+2;
                        if(heap.getelem(firstChildIx)>heap.getelem(secondChildIx)){
                            ix=firstChildIx;
                        }
                        else{
                            ix=secondChildIx;
                        }
                        if(heap.getelem(ix)>heap.getelem(i)){
                            T temp=heap.getelem(ix);
                            heap.setelem(ix,heap.getelem(i));
                            heap.setelem(i,temp);
                        }
                }
                if(2*ix+1<n){
                    ix=2*ix+1;
                    if(heap.getelem(ix)>heap.getelem(i)){
                        T temp=heap.getelem(ix);
                        heap.setelem(ix,heap.getelem(i));
                        heap.setelem(i,temp);
                    }
                }
            }
        }

        void insertHeapify(T value){
            heap.push_back(value);
            n++;
            heapify();
        }

        void insert(T value){
            insertHeapify(value);
        }

        void remove(){
            deleteHeapify();
        }

        void deleteDirect(){
            T temp=heap.getelem(0);
            heap.setelem(0,heap.getelem(n-1));
            heap.setelem(n-1,temp);
            n--;
            int ix=0;
            while(ix<n){
                int firstChildIx=2*ix+1;
                int secondChildIx=2*ix+2;
                int temp_ix;
                if(secondChildIx<n){
                    if(heap.getelem(firstChildIx)>heap.getelem(secondChildIx)){
                        temp_ix=firstChildIx;
                    }
                    else{
                        temp_ix=secondChildIx;
                    }
                }
                else if(firstChildIx<n){
                    temp_ix=firstChildIx;
                }
                else{
                    break;
                }
                if(heap.getelem(ix)<=heap.getelem(temp_ix)){
                    T temp=heap.getelem(ix);
                    heap.setelem(ix,heap.getelem(temp_ix));
                    heap.setelem(temp_ix,temp);
                    ix=temp_ix;
                }
                else{
                    break;
                }
            }
        }

        void deleteHeapify(){
            T temp=heap.getelem(0);
            heap.setelem(0,heap.getelem(n-1));
            heap.setelem(n-1,temp);
            n--;
            heapify();
        }

        /*DEBUG*/
        void printHeap(){
            for(int i=0;i<n;i++){
                cout<<heap.getelem(i)<<" ";
            }
            cout<<endl;
        }
    };

    template<typename T>class MinHeap{//creating min heap with gfg approach
        private:
        DynamicArray<T>heap;
        int n;
        public:
        MinHeap(){
            DynamicArray<T>heap=DynamicArray<T>();
            n=0;
        }
        // To heapify a subtree rooted with node i which is
        void heapifyd(int i)
        {
            int smallest = i; // Initialize smallest as root
            int l = 2 * i + 1; // left = 2*i + 1
            int r = 2 * i + 2; // right = 2*i + 2
            // If left child is larger than root
            if (l < n && heap.getelem(l) < heap.getelem(smallest))
                smallest = l;

            // If right child is larger than smallest so far
            if (r < n && heap.getelem(r) < heap.getelem(smallest))
                smallest = r;

            // If smallest is not root
            if (smallest != i) {
                T temp=heap.getelem(i);
                heap.setelem(i,heap.getelem(smallest));
                heap.setelem(smallest,temp);

                // Recursively heapifyd the affected sub-tree
                heapifyd(smallest);
            }
        }

        // Function to heapify ith node in a Heap
        // of size n following a Bottom-up approach
        void heapifyi(int i)
        {
            // Find parent
            int parent = (i - 1) / 2;
        
            if (heap.getelem(parent) > 0) {
                // For Max-Heap
                // If current node is greater than its parent
                // Swap both of them and call heapify again
                // for the parent
                if (heap.getelem(i) < heap.getelem(parent)) {
                     T temp=heap.getelem(i);
                    heap.setelem(i,heap.getelem(parent));
                    heap.setelem(parent,temp);
        
                    // Recursively heapify the parent node
                    heapifyi(parent);
                }
            }
        }
 

        // Function to delete the root from Heap
        void deleteDirect()
        {
            // Get the last element
            T lastElement = heap.getelem(n-1);

            // Replace root with last element
            heap.setelem(0,lastElement);

            // Decrease size of heap by 1
            n = n - 1;

            // heapifyd the root node
            heapifyd(0);
        }

                // Function to insert a new node to the Heap
        void insertHeapify(T Key)
        {
            // Increase the size of Heap by 1

            // Insert the element at end of Heap
            heap.push_back(Key);
            n++;
            // Heapify the new node following a
            // Bottom-up approach
            heapifyi(n-1);
        }


        /*DEBUG*/
        void printHeap(){
            for(int i=0;i<n;i++){
                cout<<heap.getelem(i)<<" ";
            }
            cout<<endl;
        }
    };
}

int main(void){
    int arr[]={5,4,6,3,2,7,8,9,0};
    nonstd::MinHeap<int>heap;
    for(int i=0;i<9;i++){
        heap.insertHeapify(arr[i]);
    }
    heap.printHeap();
    heap.deleteDirect();
    heap.printHeap();
}