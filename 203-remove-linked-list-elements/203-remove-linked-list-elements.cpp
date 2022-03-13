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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * prev=new ListNode(-1,head);
        ListNode * dummy=prev;
        while(head!=NULL){
            if(head->val==val){
                prev->next=head->next;
            }
            else
                prev=prev->next;
            head=head->next;
        }
        return dummy->next;
    }
};