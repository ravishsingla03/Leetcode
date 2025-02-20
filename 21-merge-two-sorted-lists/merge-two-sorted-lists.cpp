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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans =new ListNode();
        ListNode* temp = list1;
        ListNode* temp2 = list2;
        ListNode* fans =ans;
        while(temp && temp2){
            if(temp->val <temp2->val){
                ListNode* temp3 = new ListNode(temp->val);
                ans->next = temp3;
                ans =temp3;
                temp =temp->next;
            }
            else{
                ListNode* temp3 = new ListNode(temp2->val);
                ans->next = temp3;
                ans =temp3;
                temp2 =temp2->next;
            }
        }
        while(temp){
            ListNode* temp3 = new ListNode(temp->val);
                ans->next = temp3;
                ans =temp3;
                temp =temp->next;
        }
        while(temp2){
            ListNode* temp3 = new ListNode(temp2->val);
                ans->next = temp3;
                ans =temp3;
                temp2 =temp2->next;
        }
        return fans->next;
    }
};