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
ListNode *reverseKGroup(ListNode *head, int k) {
    if(head== NULL || k == 1){
        return head;
    }
    
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    
    ListNode *curr = dummy, *nex = dummy, *pre = dummy;
    int count = 0;
    
    while(curr -> next != NULL){
        count += 1;
        curr = curr->next;
    }
    
    while(count >= k){
        curr = pre->next;
        nex = curr->next;
        
        for(int i = 1; i<k; i++){
            curr->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = curr->next;
        }
        pre = curr;
        count -= k;
    }
    return dummy->next;
  }
};


// optimal solution:
// class Solution {
// public:
// ListNode *reverseKGroup(ListNode *head, int k) {

//     if (k<=0) return head;
//     ListNode temp(0);
//     temp.next = head;
//     ListNode* p = &temp;

//     while(p){
//         p->next = reverseList(p->next, k);
//         for(int i=0; p && i<k; i++){
//             p = p->next;
//         }
//     }

//     return temp.next;
// }

// ListNode *reverseList(ListNode *&head, int k){
//     ListNode* end = head;
//     while (end && k>0){
//         end = end->next;
//         k--;
//     }
//     if (k>0) return head;

//     ListNode *phead = end, *p = head;
//     while(p != end){
//         ListNode *q = p->next;
//         p->next = phead;
//         phead = p;
//         p = q;
//     }
//     return phead;
// }

// };
