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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*> , vector<pair<int,ListNode*>> , greater<pair<int,ListNode*>>> listpq;
        for(int i = 0; i < lists.size() ; i++){
            if(lists[i] != NULL)
            listpq.push({lists[i]->val , lists[i]});
        }
        if(listpq.size() == 0){
            return NULL;
        }
        ListNode* head = NULL;
        
        auto firstele = listpq.top();
        listpq.pop();
        
        head = firstele.second;  
        if(firstele.second->next != NULL)
        listpq.push({firstele.second->next->val , firstele.second->next});
        
        ListNode* curr = head;
        while(!listpq.empty()){
            
            auto top = listpq.top();
            listpq.pop();
            int val = top.first;
            ListNode* nextNode = top.second;
            curr->next = nextNode;
            if(nextNode == NULL){
                curr = curr->next;
                continue;
            }
            if(nextNode->next != NULL)
            listpq.push({nextNode->next->val , nextNode->next});
            curr = curr->next;
        }
        curr->next = NULL;
        return head;
    }
};