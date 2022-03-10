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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode*head=NULL,*prev=NULL;
        int carry=0;
        while(l1|| l2){
            int v1=l1?l1->val:0;
            int v2=l2?l2->val:0;
            int res=v1+v2+carry;
            carry=res/10;
            res=res%10;
            ListNode* curr=new ListNode(res);
            if(head==NULL)
                head=curr;
            if(prev)
                prev->next=curr;
            prev=curr;
            l1=l1?l1->next:NULL;
            l2=l2?l2->next:NULL;
        }
        if(carry){
            ListNode* l=new ListNode(carry);
            prev->next=l;
        }
        return head;
    }
};