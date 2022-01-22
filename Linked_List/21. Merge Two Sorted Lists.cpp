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
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         if(!l1){
//             return l2;
//         }
//         if(!l2){
//             return l1;
//         }
        
//         ListNode * head = l1;
//         if(l1->val  > l2->val){
//                 head = l2;
//                 l2 = l2->next;
//             }else{
//                 l1 = l1->next;
//             }
//         ListNode* newList = head;
//         while(l1 and l2){
//             if(l1->val  < l2->val){
//                 newList->next = l1;
//                 l1 = l1->next;
//             }else{
//                 newList->next = l2;
//                 l2 = l2->next;
//             }
//             newList = newList->next;
//         }
//         if(!l1){
//             newList->next = l2;
//         }else{
//             newList->next = l1;
//         } 
//         return head;
        
//         }
// };



class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *merged = new ListNode;
        ListNode *temp = new ListNode;
        
        // merged is equal to temp
        merged = temp;
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                temp->next = l1;
                l1 = l1->next;
            }else{
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        
        //any remaining nodes 
        while(l1 != NULL){
            temp->next = l1;
            l1 = l1->next;
            temp = temp->next;
        }
        
        while(l2 != NULL){
            temp->next = l2;
            l2 = l2->next;
            temp = temp->next;
        }
        
        return merged->next;
        
        }
};


















