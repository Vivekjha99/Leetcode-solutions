/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* curr,Node* node,vector<Node*>&vis){
        //node and curr have same value but nodes of diff graphs
        vis[node->val]=node;
        for(auto child:curr->neighbors){
            if(vis[child->val]==NULL){
                Node *newnode=new Node(child->val);
                (node->neighbors).push_back(newnode);
                dfs(child,newnode,vis);
            }
            else{
                (node->neighbors).push_back(vis[child->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        vector<Node* >vis(1000,NULL);
        Node* copy=new Node(node->val);
        vis[node->val]=copy;
        for(auto curr:node->neighbors){
            if(vis[curr->val]==NULL){
                Node* newnode=new Node(curr->val);
                copy->neighbors.push_back(newnode);
                dfs(curr,newnode,vis);
            }
            else{
                (copy->neighbors).push_back(vis[curr->val]);
            }
        }
        return copy;
        
    }
};