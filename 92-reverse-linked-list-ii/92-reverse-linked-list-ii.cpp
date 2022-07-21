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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int idx=1;
        ListNode* curr=head;
        ListNode* temp=new ListNode(0);
        ListNode* pre=temp;
        temp->next=head;
        while(curr->next ){
            if(idx==left){
                break;
            }
            pre=pre->next;
            curr=curr->next;
            idx++;
        }
        ListNode* p1=pre;
        ListNode* p2=curr;
        pre=pre->next;
        curr=curr->next;
        for(int i=1;i<=right-left;i++){
            ListNode* p3=curr->next;
            curr->next=pre;
            pre=curr;
            curr=p3;
        }
        p1->next=pre;
        p2->next=curr;
        return temp->next;
    }
};