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
    ListNode* rotateRight(ListNode* head, int k) {
        int n=1;
        if(head==NULL)return head;
        ListNode* curr=head;
        while(curr->next){
            n++;
            curr=curr->next;
        }
        k=(k%n);
        if(k==0)return head;
        int x=n-k;
        int idx=1;
        curr->next=head;
        curr=head;
        while(idx!=x){
            curr=curr->next;
            idx++;
        }
        // cout<<curr->val<<endl;
        ListNode* t=head;
        head=curr->next;
        curr->next=NULL;
        // curr=head;
        // while(curr->next)curr=curr->next;
        // curr->next=t;
        return head;
      
    }
};