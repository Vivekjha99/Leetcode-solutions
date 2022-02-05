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
struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>q;
        for(auto &x:lists){
            if(x)q.push(x);
        }
        if(q.empty())return NULL;
        ListNode* res=q.top();
        q.pop();
        if(res->next){
            q.push(res->next);
        }
        ListNode* tail=res;
        while(!q.empty()){
            tail->next=q.top();
            q.pop();
            tail=tail->next;
            if(tail->next)q.push(tail->next);
        }
        return res;
    }
};