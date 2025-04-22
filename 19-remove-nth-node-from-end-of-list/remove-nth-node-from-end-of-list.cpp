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
    ListNode* rev(ListNode* head){
        if(head==NULL){
            return NULL;
        }
        ListNode* curr = head;
        ListNode* prev =NULL;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev=curr;
            curr= next;
        }
        return prev;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = rev(head);
        ListNode* temp = head;
        for(int i=2;i<n;i++){
            temp=temp->next;
        }
        if(n==1){
            head = rev(head->next);
            return head;
        }
        ListNode* del = temp->next;
        temp->next = del->next;
        delete(del);
        head = rev(head);
        return head;
    }
};