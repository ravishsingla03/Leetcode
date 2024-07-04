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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp =head;
        ListNode* ans =new ListNode(-1);
        ListNode* anshead =ans;
        while(temp!=NULL){
            int count=0;
            if(temp->val==0){
                temp=temp->next;
                if(temp!=NULL){
                    while(temp->val!=0){
                        count+=temp->val;
                        temp =temp->next;
                    }
                ListNode* temp2= new ListNode(count);
                ans->next = temp2;
                ans=temp2; 
                }
                
            }
        }
        return anshead->next;
    }
};