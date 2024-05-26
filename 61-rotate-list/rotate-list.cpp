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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL ||head->next==NULL ||k==0){
            return head;
        }

        int count =1;
        ListNode* temp =head;
        while(temp->next){
            count++;
            temp=temp->next;
        }
        temp->next = head;

        k = k%count;
        int len = count - k ;
        while(len--){
            temp= temp->next;
        }
        ListNode* ans = temp->next;
        temp->next =NULL;
        return ans;
    }
};