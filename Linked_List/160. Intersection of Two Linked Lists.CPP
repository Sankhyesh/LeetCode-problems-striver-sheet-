// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* l2 = headB;
//         ListNode* l1 = headA;
//         int countA = 0;
//         int countB = 0;
//         while(l1 != NULL){
//             countA += 1;
//             l1 = l1->next;
//         }
//         while(l2 != NULL){
//             countB += 1;
//             l2 = l2->next;
//         }
        
//         int d = 0;
        
//         if(countA > countB){
//             d = countA - countB;
//             while(d != 0){
//                 la = la->next;
//             }
//         }else{
//             d = countB - countA;
//             while(d != 0){
//                 lb = lb->next;
//             }
//         }
        
//         while(la != lb){
//             la = la->next;
//             lb = lb->next;
//         }
        
//         return la->val;
//     }
// };



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/// optiaal solution:
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int len1 = 0, len2 = 0, diff;
        ListNode *d1 = headA;
        ListNode *d2 = headB;
        
        while(d1 != NULL || d2 != NULL){
            if(d1 != NULL){
                len1++;
                d1 = d1->next;
            }
            if(d2 != NULL){
                len2++;
                d2 = d2->next;
            }   
        }
            diff = len1 - len2;
              
              if(diff<0){
                  while(diff++ != 0){
                      headB = headB->next;
                  }
              }else{
                  while(diff-- != 0){
                      headA = headA->next;
                  }
              }
              
              while(headA != NULL){
                  if(headA  == headB){
                      return headA;
                  }
                  headB = headB->next;
                  headA = headA->next;
              }
              return headA;     
    }
};


/// optiaal solution: second solution
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* d1 = headA;
//         ListNode* d2 = headB;
        
//         while(d1 != d2 ){
//             if(d1 == NULL){
//                 d1 = headA;
//             }else{
//                 d1 = d1->next;
//             }
            
//             if(d2 == NULL){
//                 d2 = headB;
//             }else{
//                 d2 = d2->next;
//             }
//         }
//         return d1;
//     }
// };
