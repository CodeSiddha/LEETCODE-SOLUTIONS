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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        ListNode *temp = head;
        while(temp){
            temp = temp -> next;
            n++;
        }
        temp = head;
        int n1 = k;
        int n2 = n - k + 1;
        ListNode *temp1 , *temp2;
        for(int i = 1 ; i <= n ; i++){
            if(i == n1){
                temp1 = temp;
            }
            if(i == n2){
                temp2 = temp;
            }
            temp = temp -> next;
        }
        swap(temp1->val , temp2->val);
        return head;
    }
};