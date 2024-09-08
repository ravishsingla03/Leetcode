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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> v;
        ListNode* temp=head;
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        temp=head;

        if(count<k){
            while(k--){
                if(temp){
                    ListNode* temp3  = new ListNode(temp->val);
                    v.push_back(temp3);
                    temp = temp->next;
                }
                else{
                    v.push_back(NULL);
                }
            }
            return v;
        }
        
        int num =count%k;
        int size =count/k;

        //for first num part;
        for(int i=0;i<num;i++){
            int count2=0;
            while(count2<size){
                count2++;
                temp=temp->next;
            }
            ListNode* temp2 = temp->next;
            temp->next =NULL;
            v.push_back(head);
            head =temp2;
            temp =temp2;
        }
        //for remaing parts
        for(int i=num;i<k;i++){
            int count2=1;
            while(count2<size){
                count2++;
                temp=temp->next;
            }
            ListNode* temp2;
            if(temp==NULL){
                v.push_back(head);
                return v;
            }
            temp2 = temp->next;
            temp->next =NULL;
            v.push_back(head);
            head =temp2;
            temp =temp2;
        }
        return v;
    }
};