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
    ListNode* middleNode(ListNode* head) {
        ListNode *p=NULL, *q=NULL;
        p=head;
        q=head;
        int p_count = 0;
        int q_count = 0;
        while(q!=NULL && q->next != NULL && q->next->next!=NULL){
            p = p->next;
            p_count += 1;
            q = q->next->next;
            q_count += 2;
        }
        
        while(q->next != NULL){
            q = q->next;
            q_count += 1;
        }
        q_count += 1;
        if(q_count%2 ==0){
            p = p->next;
        }
        return p;
    }
};
