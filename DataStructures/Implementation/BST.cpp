#include<iostream>
using namespace std;

namespace nonstd{

	template<typename T>class Node{
		public:
			T value;
			Node<T>* parent=nullptr;
			Node<T>* left=nullptr;
			Node<T>* right=nullptr;
	};

	template<typename T>class BinarySearchTree{
		private:
		Node<T>* root;

		public:

		BinarySearchTree(){
			root=nullptr;
		}

		void insert(T value){
			Node<T>* temp=new Node<T>();
			temp->value=value;
			Node<T>* x=root;
			Node<T>* y=nullptr;
			while(x!=nullptr){
				y=x;
				if(temp->value < x->value){
					x=x->left;
				}
				else{
					x=x->right;
				}
			}
			temp->parent=y;
			if(y==nullptr){
				root=temp;
			}
			else if(temp->value<y->value){
				y->left=temp;
			}
			else y->right=temp;
		}

		void inorder_walk(Node<T>* x){
			if(x!=nullptr){
				inorder_walk(x->left);
				cout<<x->value<<endl;
				inorder_walk(x->right);
			}
			else return;
		
		}

		void preorder_walk(Node<T>* x){
			if(x!=nullptr){
				preorder_walk(x->right);
				cout<<x->value<<endl;
				preorder_walk(x->left);
			}
			else return;
		}

		void inorder_walkFromRoot(){
			inorder_walk(root);
		}

		void preorder_walkFromRoot(){
			preorder_walk(root);
		}
		
		
		T findMinimum(){//Find the leftmost element
			Node<T>* x=root;
			while(x->left!=nullptr){
				x=x->left;
			}
			return x->value;
		}

		T findMaximum(){
			Node<T>* x=root;
			while(x->right!=nullptr){
				x=x->right;
			}
			return x->value;

		}



	};


}



int main(void){
	nonstd::BinarySearchTree<int> BST=nonstd::BinarySearchTree<int>();
	for(int i=0;i<10;i++){
		BST.insert(i);
	}

	BST.preorder_walkFromRoot();
	cout<<BST.findMinimum()<<endl;
	cout<<BST.findMaximum()<<endl;
	return 0;
}
