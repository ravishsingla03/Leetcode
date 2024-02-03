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
    int getDecimalValue(ListNode* head) {
         ListNode* temp=head;
            
            if(head==NULL){
                return 0;
            }
            long long unsigned int ans=0;
            while(head!=NULL){
                ans =(ans*2 + head->val)%1000000007;
                head=head->next;
            }
            return ans;
    }
};