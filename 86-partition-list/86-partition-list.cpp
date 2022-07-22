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
    ListNode* partition(ListNode* head, int x) {
        ListNode* h1=new ListNode(-1);
        ListNode* head1=h1;
        ListNode* h2=new ListNode(-1);
        ListNode* head2=h2;
        while(head){
            if(head->val<x){
                h1->next=head;
                h1=h1->next;
            }
            else {
                h2->next=head;
                h2=h2->next;
            }
            head=head->next;
        }
        h2->next=NULL;
        h1->next=head2->next;
        return head1->next;
        
    }
};