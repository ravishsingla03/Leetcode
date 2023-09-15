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
        if(head==NULL){
            return head;
        }
        while(head!=NULL && head->val==val){
            head=head->next;
        }
        if(head==NULL){
            return head;
        }

        ListNode* temp=head;
        ListNode* temp2=head->next;

        while(temp!=NULL && temp2!=NULL){
            while(temp2!=NULL && temp2->val==val){
                temp2=temp2->next;
                temp->next=temp2;
            }
            if(temp!=NULL && temp2!=NULL){
                temp=temp->next;
                temp2=temp2->next;
            }
        }
        return head;
    }
};