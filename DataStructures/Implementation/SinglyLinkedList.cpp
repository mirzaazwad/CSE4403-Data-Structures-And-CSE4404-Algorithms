#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

namespace Singly{
    template<typename T>class Node{
        public:
        T value;
        Node<T>* next;
    };



    template<typename T>class LinkedList{
        public:
        Node<T>* head;
        Node<T>* tail;

        void push_front(T key){
            Node<T> *newNode=new Node<T>();
            newNode->value=key;
            newNode->next=head;
            if(head==nullptr){
                tail=newNode;
            }
            head=newNode;
        }

        void pop_front(){
            Node<T> *temp=new Node<T>();
            temp=head;
            head=head->next;
            delete(temp);
        }

        void push_back(T key){
            Node<T>* newNode=new Node<T>();
            newNode->value=key;
            newNode->next=nullptr;
            if(head==nullptr){
                head=newNode;
                tail=newNode;
            }
            else{
                Node<T>* last=new Node<T>();
                last=head;
                while(last->next!=nullptr){
                    last=last->next;
                }
                last->next=newNode;
            }
        }

        void fpush_back(T key){
            Node<T>* newNode=new Node<T>();
            newNode->value=key;
            newNode->next=nullptr;
            if(head==nullptr){
                head=newNode;
                tail=newNode;
            }
            else if(head->next==nullptr){
                head->next=newNode;
                tail=newNode;
            }
            else{
                tail->next=newNode;
                tail=newNode;
            }
        }

        void add_after(Node<T>* node,int key){
            Node<T>* temp=node;
            Node<T>* newNode=new Node<T>();
            newNode->value=key;
            newNode->next=temp->next;
            temp->next=newNode;
        }
        

        void add_before(Node<T>* node,int key){
            Node<T>* newNode=new Node<T>();
            Node<T>* temp=head;
            if(head==node){
                push_front(key);
                return;
            }
            if(head->next==node){
                newNode->value=key;
                newNode->next=head->next;
                head->next=newNode;
            }
            while(temp->next->next!=node){
                temp=temp->next;
            }
            newNode->value=key;
            newNode->next=temp->next->next;
            temp->next=newNode;
        }

        void pop_back(){
            Node<T>* temp=new Node<T>();
            temp=head;
            while(temp->next->next!=nullptr){
                temp=temp->next;
            }
            Node<T>* deletable=new Node<T>();
            deletable=temp->next;
            temp->next=nullptr;
            delete(deletable);
        }

        T top_front(){
            return head->value;
        }

        T bottom_back(){
            return tail->value;
        }

        void printList(){
            Node<T>* temp=new Node<T>();
            temp=head;
            while(temp!=nullptr){
                cout<<temp->value<<" ";
                temp=temp->next;
            }
        }

        void reverse()
        {
            // Initialize current, previous and next pointers
            Node<T>* current = head;
            Node<T> *prev = nullptr, *next = nullptr;
    
            while (current != nullptr) {
                // Store next
                next = current->next;
                // Reverse current node's pointer
                current->next = prev;
                // Move pointers one position ahead.
                prev = current;
                current = next;
            }
            head = prev;
        }


    };
}

int main()
{
    fastio;
    Singly::LinkedList<int> list= Singly::LinkedList<int>();
    for(int i=0;i<15;i++){
        list.push_back(i);
    }
    list.pop_back();
    list.pop_front();
    list.printList();
    return 0;
}
