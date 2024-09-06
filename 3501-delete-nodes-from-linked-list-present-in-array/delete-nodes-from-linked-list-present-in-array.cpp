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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector<int>v;
        sort(nums.begin(),nums.end());
        while(head){
            if(!binary_search(nums.begin(),nums.end(),head->val)){
                v.push_back(head->val);
            }
            head = head->next;
        }
        ListNode* temp = new ListNode(-1);
        ListNode* tempans = temp;

        for(auto i: v){
            ListNode * temp1 = new ListNode(i);
            temp->next = temp1;
            temp = temp->next;
        }
        return tempans->next;


        return NULL;
    }
};