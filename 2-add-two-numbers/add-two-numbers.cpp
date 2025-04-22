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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* fans = ans;
        int carry =0;
        while(l1 && l2){
            int sum = (l1->val+l2->val + carry);
            carry = sum/10;
            ListNode* temp = new ListNode(sum%10);
            ans->next = temp;
            ans = ans->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int sum = (l1->val + carry);
            carry = sum/10;
            ListNode* temp = new ListNode(sum%10);
            ans->next = temp;
            ans = ans->next;
            l1 = l1->next;
        }
        while(l2){
            int sum = (l2->val + carry);
            carry = sum/10;
            ListNode* temp = new ListNode(sum%10);
            ans->next = temp;
            ans = ans->next;
            l2 = l2->next;
        }
        if(carry){
            ListNode* temp = new ListNode(1);
            ans->next = temp;
        }
        return fans->next;
    }
};