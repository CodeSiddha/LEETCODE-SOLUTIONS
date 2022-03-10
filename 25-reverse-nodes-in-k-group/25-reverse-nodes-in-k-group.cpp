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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *PreviousNode , *currentNode , *nextNode , *temp;
        PreviousNode = nextNode = NULL;
        currentNode = temp = head;
        int count = 0;
        
        for(int i = 0 ; i < k ; i++){
            if(!temp)
                return head;
            temp = temp -> next;
        }
        
        
        while(currentNode != NULL && count < k){
            nextNode = currentNode->next;
            currentNode->next = PreviousNode;
            PreviousNode = currentNode;
            currentNode = nextNode;
            count++;
        }
        if(nextNode != NULL)
        head->next = reverseKGroup(nextNode , k);
        return PreviousNode;
    }
};