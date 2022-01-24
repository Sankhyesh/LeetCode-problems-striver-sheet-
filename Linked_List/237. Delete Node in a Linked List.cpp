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
//     void deleteNode(ListNode* node) {
//         ListNode* temp = node;
//         ListNode* pre;
//         while(temp->next != NULL){
//             pre = temp;
//             temp->val = temp->next->val;
//             temp = temp->next;
//         }
//         pre->next = NULL;
//     }
// };

// optimal 
class Solution {
 public:
  void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
  }
};
