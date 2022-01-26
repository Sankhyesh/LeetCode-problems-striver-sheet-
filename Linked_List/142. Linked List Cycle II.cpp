/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         ListNode pos = -1;
//         if(head  == NULL || head->next ==  NULL){
//             return NULL;
//         }
//         ListNode *slow = head->next;
//         ListNode *fast = head->next->next;
        
//         while( fast != NULL and fast->next!= NULL and (slow != fast)){
//             slow = slow->next;
//             fast = fast->next->next;
//         }
        
//         if (fast == NULL or fast->next == NULL){
//             return NULL;
//         }
//         slow = head;
//         while(slow != fast){
//             slow = slow->next;
//             fast = fast->next;
//         }
//         return slow;
//     }
// };


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
  
         if(head ==NULL || head->next == NULL){
             return NULL;
         }    
        
        ListNode *slow = head, *fast=head, *start=head;
        while(fast->next != NULL and fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                while (fast!=start){
                    fast = fast->next;
                    start = start->next;
                }
                return start;
            }
        }
        return NULL;
    }
};
