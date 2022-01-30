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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=1;
        ListNode* curr=head;
        vector<ListNode*>res(k,NULL);
        if(head==NULL)return res;
        while(curr->next){
            len++;
            curr=curr->next;
        }
        int x=len/k;
        int y=len%k;
        curr=head;ListNode*prev=NULL;
        for(int i=0;i<k;i++,y--){
            res[i]=curr;
            for(int j=0;j<x+(y>0);j++){
                prev=curr;
                curr=curr->next;
            }
            prev->next=NULL;
        }
        return res;
        
    }
};