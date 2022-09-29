/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* temp;
    bool isPalindrome(ListNode* head) {
       temp=head;
        return checkPalindrome(head);
    }
    
    bool checkPalindrome(ListNode* head){
        if(head==nullptr)return true;
        bool res=checkPalindrome(head->next) & (head->val==temp->val);
        temp=temp->next;
        return res;
    }


};
