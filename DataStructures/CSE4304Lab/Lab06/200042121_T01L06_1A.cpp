#include<iostream>
using namespace std;

namespace nonstd{
    template<typename T>class Node{
        public:
        T data;
        Node<T>* parent;
        Node<T>* right;
        Node<T>* left;
        Node(T value){
            data=value;
            left=nullptr;
            right=nullptr;
            parent=nullptr;
        }
    };

    template<typename T>class BinarySearchTree{
        private:
        Node<T>* root=nullptr;

        public:

        void Insert(T key){
            Node<T>* insertNode=new Node<T>(key);
			Node<T>* t=root;
			Node<T>* temp=nullptr;
			while(t!=nullptr){
				temp=t;
				if(insertNode->data < t->data){
					t=t->left;
				}
				else{
					t=t->right;
				}
			}
			insertNode->parent=temp;
			if(temp==nullptr){
				root=insertNode;
			}
			else if(insertNode->data<temp->data){
				temp->left=insertNode;
			}
			else temp->right=insertNode;
		}

        Node<T>* Search(T key,Node<T>* t=nullptr,bool set=false){
            if(!set){
                set=true;
                t=root;
            }
            if(t==nullptr)return nullptr;
            if(key==t->data)return t;
            else if(key<t->data)return Search(key,t->left,true);
            else return Search(key,t->right,true);
        }

        void Inorder(Node<T>* t=nullptr,bool set=false){
            if(t==nullptr){
                if(!set){
                    t=root;
                    set=true;
                    Inorder(t,set);
                }
                return;
            }
			Inorder(t->left,set);
			cout<<t->data<<" ";
			Inorder(t->right,set);
		}

        /*DEBUG CODE START*/
        // T getRootValue(){
        //     return root->data;
        // }

        // Node<T>* getRoot(){
        //     return root;
        // }
        /*DEBUG CODE END*/

        Node<T>* Predecessor(Node<T>* p){
            while(p && p->right!=nullptr){
                p=p->right;
            }
            return p;
        }

        T InorderPredecessor(){
            return Predecessor(root->left)->data;
        }

        Node<T>* Successor(Node<T>* p){
            while(p && p->left!=nullptr){
                p=p->left;
            }
            return p;
        }

        T InorderSuccessor(){
            return Successor(root->right)->data;
        }


    };

}



int main(void){
    nonstd::BinarySearchTree<int>tree=nonstd::BinarySearchTree<int>();
    int n;
    while(cin>>n,n!=-1){
        bool found=false;
        for(int i=-3;i<=3;i++){
            if(tree.Search(n+i)){
                found=true;
                break;
            }
        }
        if(!found){
            tree.Insert(n);
        }
        tree.Inorder();
        if(found){
            cout<<"(Reservation failed)";
        }
        cout<<endl;
    }
}