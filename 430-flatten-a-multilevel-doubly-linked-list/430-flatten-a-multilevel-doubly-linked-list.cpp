/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* h=head;
        while(h){
            if(h->child){
                Node* temp=h->next;
                h->next=h->child;
                h->next->prev=h;
                h->child=NULL;
                Node* p=h->next;
                while(p->next)p=p->next;
                p->next=temp;
                if(temp)temp->prev=p;
            }
            h=h->next;
        }
        return head;
    }
};