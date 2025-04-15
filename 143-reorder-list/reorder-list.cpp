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
    ListNode* reverse(ListNode* head){
        if(head==NULL){
            return NULL;
        }
        ListNode* prev=NULL;
        ListNode* curr = head;

        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* slow= head;
        ListNode* fast= head;
        while(fast){
            slow = slow->next;
            fast = fast->next;
            if(fast){
                fast=fast->next;
            }
        }
        slow = reverse(slow);
        ListNode* temp = head;

        while(temp){
            ListNode* tempnext = temp->next;
            temp->next = slow;
            temp = tempnext;
            if(slow){
                ListNode* slownext = slow->next;
                slow->next = temp;
                slow = slownext;
            }
            else{
                break;
            }
        }
    }
};