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
    int countnodes(ListNode* head){
        int cnt=0;
        while(head){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int n=countnodes(head);
        int idx=0;
        ListNode* r=head;
        ListNode* p1=head,*p2=head;
        while(head){
            idx++;
            if(idx==k)p1=head;
            if(idx==(n-k+1))p2=head;
            head=head->next;
        }
        swap(p1->val,p2->val);
        return r; 
    }
};