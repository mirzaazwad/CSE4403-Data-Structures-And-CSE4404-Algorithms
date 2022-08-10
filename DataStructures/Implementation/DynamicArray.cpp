#include<bits/stdc++.h>
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
}


int main(void){
    nonstd::DynamicArray<string>arr=nonstd::DynamicArray<string>();
    for(int i=0;i<20;i++){
        arr.push_back("Hello, world!");
    }
    for(int i=0;i<arr.size;i++){
        cout<<i+1<<": "<<arr.getelem(i)<<endl;
    }
}
