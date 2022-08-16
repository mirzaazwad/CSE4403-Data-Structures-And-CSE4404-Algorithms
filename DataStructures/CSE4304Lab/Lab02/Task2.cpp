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

        void clear(){
            size=0;
            capacity=2;
            delete[] array;
            array=new T[capacity];

        }
        

    };
}

nonstd::DynamicArray<int> sum(nonstd::DynamicArray<int> a){
    int i=a.Size()-1;
    int carry=0;
    int j;
    for(j=i;j>=0;j--){
        if(a.Get(j)==9){
            carry=1;
            a.Set(j,0);
            continue;
        }
        a.Set(j,a.Get(j)+1);
        carry=0;
        break;
    }
    if(carry){
        nonstd::DynamicArray<int>temp=nonstd::DynamicArray<int>();
        temp.Push_Back(carry);
        for(int j=0;j<a.Size();j++){
            temp.Push_Back(a.Get(j));
        }
        return temp;
    }
    else{
        return a;
    }

}


int main(void){
    nonstd::DynamicArray<int>arr=nonstd::DynamicArray<int>();
    int n;
    while(cin>>n){
        arr.Push_Back(n);
    }
    nonstd::DynamicArray<int>ans=sum(arr);
    for(int i=0;i<ans.Size();i++){
        cout<<ans.Get(i)<<" ";
    }
    cout<<endl;


}
