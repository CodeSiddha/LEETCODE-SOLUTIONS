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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int totalNode = 0;
        ListNode* temp = head;
        while(temp){
            totalNode++;
            temp = temp -> next;
        }
        int deletethis = totalNode - n;
        temp = head;
        ListNode* prev = NULL;
        while(deletethis--){
            prev = temp;
            temp = temp->next;
        }
        if(prev){
            prev->next = temp->next;
            delete temp;
        }else{
            head = temp -> next;
            delete temp;
        }
        return head;
    }
};