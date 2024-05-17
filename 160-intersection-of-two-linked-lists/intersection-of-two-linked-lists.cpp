/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *heada, ListNode *headb) {
        vector<ListNode*>v;
        vector<ListNode*>v1;
        while(heada){
            v.push_back(heada);
            heada =heada->next;
        }
        while(headb){
            v1.push_back(headb);
            headb =headb->next;
        }
        int i =v.size()-1;
        int j =v1.size()-1;

        if(v[i]!=v1[j]){
            return NULL;
        }
        while(i>=0 && j>=0 && v[i]==v1[j]){
            cout<<" fw "; 
            i--;
            j--;
        }
        cout<<i;
        return v[i+1];
    }
};