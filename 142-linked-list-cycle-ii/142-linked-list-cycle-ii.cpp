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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL){
            return NULL;
        }
        ListNode *slow = head , *fast = head;
        do{
            if(slow->next == NULL){
                return NULL;
            }
            slow = slow->next;
            if(fast->next == NULL || fast->next->next == NULL){
                return NULL;
            }
            fast = fast->next->next;
        }while(slow != fast);
        fast = head;
        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;
    }
};