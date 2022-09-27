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
            //t is traversing pointer
            Node<T>* t=root;
            Node<T>* temp=nullptr;
            Node<T>* ptr;
            if(root==nullptr){
                ptr=new Node<T>(key);
                root=ptr;
                return;
            }
            while(t!=nullptr){
                temp=t;
                if(key==t->data){
                    return;
                }
                else if(key<t->data){
                    t=t->left;
                }
                else{
                    t=t->right;
                }
            }
            ptr=new Node<T>(key);
            if(ptr->data<temp->data){
                temp->left=ptr;
            }
            else temp->right=ptr;
        }

        void InsertSirsMethod(T key){
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

        Node<T>* Search(int key,Node<T>* t=nullptr,bool set=false){
            if(!set){
                set=true;
                t=root;
            }
            if(t==nullptr)return nullptr;
            if(key==t->data)return t;
            else if(key<t->data)return Search(key,t->left,true);
            else return Search(key,t->right,true);
        }

        void inorder_walk(Node<T>* t=nullptr,bool set=false){
			if(!set){
				set=true;
				t=root;
			}
			if(t!=nullptr){
				inorder_walk(t->left,set);
				cout<<t->data<<" ";
				inorder_walk(t->right,set);
			}
			else{
                return;
            }
		}

        Node<T>* Delete(T key,Node<T>* t=nullptr,bool set=false){
            Node<T>* temp;
            if(t==nullptr){
                if(!set){
                    t=root;
                    Delete(key,t,true);
                }
                return nullptr;
            }
            if(t->left==nullptr && t->right==nullptr){
                if(t==root){
                    root=nullptr;
                }
                delete t;
            }

            if(key<t->data){
                t->left=Delete(key,t->left,true);
            }
            else if(key>t->data){
                t->right=Delete(key,t->right,true);
            }
            else{
                if(Height(t->left)>Height(t->right)){
                    temp=Predecessor(t->left);
                    t->data=temp->data;
                    t->left=Delete(temp->data,t->left,true);
                }
                else{
                    temp=Successor(t->right);
                    t->data=temp->data;
                    t->right=Delete(temp->data,t->right,true);
                }
            }
            return t;
        }

        int Height(Node<T>* p){
            int x,y;
            if(p==nullptr){
                return 0;
            }
            x=Height(p->left);
            y=Height(p->right);
            return x>y?x+1:y+1;
        }

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
    nonstd::BinarySearchTree<int> BST=nonstd::BinarySearchTree<int>();
    BST.InsertSirsMethod(30);
    BST.InsertSirsMethod(20);
    BST.InsertSirsMethod(40);
    BST.InsertSirsMethod(10);
    BST.InsertSirsMethod(25);
    BST.InsertSirsMethod(35);
    BST.InsertSirsMethod(50);
    BST.inorder_walk();
    cout<<endl;
    BST.Delete(50);
    BST.inorder_walk();
    cout<<endl;
    nonstd::Node<int>* ptr=BST.Search(50);
    if(ptr==nullptr){
        cout<<"Not Found"<<endl;
    }
    else{
        cout<<"Found: ";
        cout<<ptr->data<<endl;
    }


    return 0;
}