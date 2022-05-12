/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(0);
        Node *temp = dummy;
        Node *oldsize = head , *list = dummy;
        int n = 0;
        while(oldsize){
            n++;
            oldsize = oldsize -> next;
        }
        // unordered_map<Node*,Node*> rand;
        Node *oldnode = head;
        unordered_map<int,Node*> ind;        
        unordered_map<Node*,int> rand;
        for(int i = 1 ; i <= n ; i++){
            rand[oldnode] = i;
            oldnode = oldnode->next;
            if(oldnode == NULL){
                break;
            }
        }
        rand[NULL] = n + 1;
        oldnode = head;
        for(int i = 1 ; i <= n ; i++){
            Node* node = new Node(oldnode->val);
            list->next = node;
            ind[i] = node;
            list = list -> next;
            oldnode = oldnode -> next;
        }
        ind[n + 1] = NULL;
        list = dummy->next;
        oldnode = head;
        for(int i = 1 ; i <= n ; i++){
            list->random = ind[rand[oldnode->random]];
            list = list -> next;
            oldnode = oldnode -> next;
        }
        return dummy->next;
    }
};