/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int val) {
    if (!root) return root;
    if (val < root->val) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->val) {
        root->right = deleteNode(root->right, val);
    } else {
        /* Leaf node case */
        if (!root->left && !root->right) {
            delete(root);
            return nullptr;
        }
        /* 1 child case */
        if (!root->left ) {
            TreeNode *ret = root->right; 
            delete(root);
            return ret;
        }
         else if (!root->right ) {
            TreeNode *ret = root->left; 
            delete(root);
            return ret;
        }
        /* 2 child case */
        if (root->left && root->right) {
            TreeNode *tmp = root->right;
            while (tmp->left) {
                tmp = tmp->left;
            }
            root->val = tmp->val;
            root->right = deleteNode(root->right, root->val);
        }
    }
    return root;
    }
    

    
    TreeNode* InorderSuccessor(TreeNode* p){
        while(p && p->left!=nullptr){
                p=p->left;
            }
            return p;
    }
};
