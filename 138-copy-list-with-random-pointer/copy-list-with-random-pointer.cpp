/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* ans = new Node(-1);
        Node* anshead = ans;

        Node* temp = head;
        vector<Node*>v;
        unordered_map<Node*,int>headnodes;
        int i=0;
        while(head){
            Node* temp = new Node(head->val);
            v.push_back(temp);
            ans->next = temp;
            ans = temp;
            headnodes[head]=i++;
            head=head->next;
        }
        ans = anshead->next;
        while(temp){
            if(temp->random==NULL){
                ans->random=NULL;
            }
            else{
                int x = headnodes[temp->random];
                ans->random = v[x];
            }
            temp=temp->next;
            ans=ans->next;
        }

        return anshead->next;
    }
};