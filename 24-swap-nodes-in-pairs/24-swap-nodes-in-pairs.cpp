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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* prev=dummy;
        while(prev->next && prev->next->next){
            ListNode* curr=prev->next;
            ListNode* forw=curr->next;
            ListNode* temp=forw->next;
            forw->next=curr;
            curr->next=temp;
            prev->next=forw;
            prev=curr;//going to next adjacent pairs
        }
        return dummy->next;
    }
};