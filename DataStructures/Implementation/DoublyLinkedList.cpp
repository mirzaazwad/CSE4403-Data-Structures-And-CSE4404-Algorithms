#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

namespace Doubly{
    template<typename T>class Node{
        public:
        T value;
        Node<T>* next;
        Node<T>* previous;
    };


    template<typename T>class LinkedList{
        public:
        Node<T>* head;
        Node<T>* tail;

        void push_front(T key){
            Node<T> *newNode=new Node<T>();
            newNode->value=key;
            newNode->next=head;
            newNode->previous=nullptr;
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
            head->previous=nullptr;
        }

        void push_back(T key){
            Node<T>* newNode=new Node<T>();
            newNode->value=key;
            newNode->next=nullptr;
            newNode->previous=nullptr;

            if(head==nullptr){
                head=newNode;
                tail=newNode;
            }
            else if(head->next==nullptr){
                newNode->previous=head;
                head->next=newNode;
                tail=newNode;
            }
            else{
                newNode->previous=tail;
                tail->next=newNode;
                tail=newNode;
            }
        }

        void add_after(Node<T>* node,int key){
            Node<T>* newNode=new Node<T>();
            newNode->value=key;
            newNode->next=node->next;
            newNode->previous=node;
            node->next=newNode;
        }

        void add_before(Node<T>* node,int key){
            Node<T>* newNode=new Node<T>();
            newNode->value=key;
            newNode->next=node;
            newNode->previous=node->previous;
            node->previous=newNode;

        }

        void pop_back(){
            Node<T>* temp=new Node<T>();
            temp=tail;
            tail=tail->previous;
            tail->next=nullptr;
            delete(temp);
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
            cout<<endl;
        }

        void reversePrintList(){
            Node<T>* temp=new Node<T>();
            temp=tail;
            while(temp!=nullptr){
                cout<<temp->value<<" ";
                temp=temp->previous;
            }
            cout<<endl;
        }

        void reverse()
        {
            Node<T>* temp = nullptr;
            Node<T>* current = head;
            tail=head;
            /* swap next and prev for all nodes of
            doubly linked list */
            while (current != nullptr) {
                temp = current->previous;
                current->previous = current->next;
                current->next = temp;
                current = current->previous;
            }
            /* Before changing head, check for the cases like empty
            list and list with only one node */
            if (temp != nullptr)
                head = temp->previous;
        }


    };
}

int main()
{
    fastio;
    Doubly::LinkedList<int> list= Doubly::LinkedList<int>();
    for(int i=0;i<15;i++){
        list.push_back(i);
    }
    list.pop_back();
    list.pop_front();
    list.printList();
    list.reverse();
    list.reversePrintList();
    return 0;
}