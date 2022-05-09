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
        if(head == NULL){
            return NULL;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *slow = dummy , *fast = dummy , *lastnode , *temp = head;
        int n = 0;
        while(temp){
            n++;
            temp = temp -> next;
        }
        k = (k % n); 
        for(int i = 1 ; i <= k + 1 ; i++){
            fast = fast -> next;
        }
        while(fast){
            slow = slow->next;
            if(fast->next == NULL){
                lastnode = fast;
            }
            fast = fast->next;
        }
        lastnode->next = head;
        head = slow->next;
        slow -> next = NULL;
        return head;
    }
};