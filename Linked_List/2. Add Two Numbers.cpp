
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;
        
        while(l1 != NULL || l2 != NULL || carry){
            int sum =0;
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;
            ListNode* node = new ListNode(sum%10);
            temp->next = node;
            temp = temp->next;
        }
        return dummy->next;
    }
};




// 2nd attempt wrong anwer
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode *lr = l1;
//         ListNode *ls = l2;
        
//         ListNode *dummy = new ListNode();
//         ListNode *temp = dummy;
        
//         long lr_sum = 0;
//         while(lr != NULL){
//              lr_sum = lr->val + (lr_sum * 10);
//             lr = lr->next;
//         }
//         long revlr = 0;
//         while(lr_sum){
//             long digit = (lr_sum)%(10);
//             lr_sum = lr_sum / 10;
//             revlr = digit + (revlr * 10);
//         }
//         long ll_sum = 0;
//         while(ls != NULL){
//             ll_sum = ls->val + (ll_sum * 10);
//             ls = ls->next;
//         }
//         long revll = 0;
//         while(ll_sum){
//             long digit = ll_sum%10;
//             ll_sum = ll_sum / 10;
//             revll = digit + (revll * 10);
//         }
        
//         long total = revlr + revll;
//         if(total == 0){
//             ListNode *res = new ListNode(0);
//             temp->next = res;
//             temp = temp->next;
//         }
//         while(total){
//             ListNode *res = new ListNode( total % 10);
//             total = total/10;
//             temp->next = res;
//             temp = temp->next;
//         }
        
//         return dummy->next;
//     }
// };


// ###wrong array

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode *lr = l1;
//         ListNode *ls = l2;
        
//         ListNode *dummy = new ListNode();
//         ListNode *temp = dummy;
        
//         int lr_sum = 0;
//         while(lr != NULL){
//              lr_sum = lr->val + (lr_sum * 10);
//             lr = lr->next;
//         }
        
//         int ll_sum = 0;
//         while(ls != NULL){
//             ll_sum = ls->val + (ll_sum * 10);
//             ls = ls->next;
//         }
        
//         int total = lr_sum + ll_sum;
//         if(total == 0){
//             ListNode *res = new ListNode(0);
//             temp->next = res;
//             temp = temp->next;
//         }
//         while(total){
//             ListNode *res = new ListNode( total % 10);
//             total = total/10;
//             temp->next = res;
//             temp = temp->next;
//         }
        
//         return dummy->next;
//     }
// };
