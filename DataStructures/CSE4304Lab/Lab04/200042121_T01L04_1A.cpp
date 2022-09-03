/*
*Author: Mirza Mohammad Azwad
*Institude: Islamic University of Technology
In the name of Allah, the Lord of Mercy, the Giver of Mercy
*/
#include<iostream>
#include<cstring>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
using namespace std;
 
#define ll long long
#define endl "\n"
 
template<typename T>class Queue{
    private:
    const int SIZE=15;
    T items[15];
    int head, tail;
    public:
    Queue(){
        memset(items,0,sizeof(items));
        head=-1;
        tail=-1;
    }
    void Enqueue (T x){
        if(isFull()){
            cout<<"Queue is full"<<endl;
                return;
        }
        else{
            tail=(tail+1)%SIZE;
            if(tail==head || items[tail]!=0){
                cout<<"Queue is full"<<endl;
                return;
            }
            else{
                items[tail]=x;
            }
            if(head==-1)head++;
        }
    }

    T Dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else{
            T value=items[head];
            items[head]=0;
            if(head==tail){
                head=-1;
                tail=-1;
            }
            else{
                head=(head+1)%SIZE;
            }
            return value;
        }
    }

    bool isEmpty(){
        if(head==-1)return true;
        else return false;
    }

    bool isFull(){
        if(head==tail+1)return true;
        else if(head==0 && tail==SIZE-1)return true;
        else return false;
    }

    void front(){
        cout<< items[head]<<endl;
    }

    void back(){
        cout<< items[tail]<<endl;
    }
    //DEBUG
    void display(){
        for(int i=0;i<SIZE;i++) cout<< items[i]<<" ";
        cout<<endl;
    }

};

int main()
{
    fastio;
    Queue<int>q=Queue<int>();
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(20);
    q.Enqueue(20);
    q.Enqueue(20);
    q.Enqueue(20);
    /*DEBUG*/q.display();
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    /*DEBUG*/q.display();


    return 0;
}