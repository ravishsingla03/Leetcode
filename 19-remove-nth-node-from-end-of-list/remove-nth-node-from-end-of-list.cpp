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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp =head;
        int count= 0;
        while(temp){
            count++;
            temp=temp->next;
        }
        if(count==1){
            return NULL;
        }
        if(n==count){
            return head->next;
        }
        temp=head;
        while(count-n>1){
            temp=temp->next;
            count--;
        }
        ListNode*temp2 = temp->next->next;
        temp->next = temp2;
        return head;
    }
};