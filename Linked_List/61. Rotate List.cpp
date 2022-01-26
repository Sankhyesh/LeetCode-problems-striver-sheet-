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
        ListNode  *pre = head;
        if(head == NULL || head->next == NULL){
            return head;
        }
        int count = 1;
        
        while(pre->next != NULL){
            pre = pre->next;
            count++;
        }
        
        pre->next = head;
        
        k = k%count;
        int len = count - k;
        
        while(len--){
            pre = pre->next;
        }
        
        head = pre->next;
        pre->next = NULL;
            
        
        return head;
    }
};
