#include<bits/stdc++.h>
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


int main(void){
    nonstd::DynamicArray<int>arr=nonstd::DynamicArray<int>();
    for(int i=0;i<15;i++){
        arr.Push_Back(i);
    }
    arr.Remove(4);
    for(int i=0;i<arr.Size();i++){
        cout<<arr.Get(i)<<endl;
    }

}
