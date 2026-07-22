/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       ListNode* slow,*fast,*ptr;
       slow=head;
       fast=head;
        ptr=head;
       while(fast && fast->next)
       {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            while(ptr!=slow)
            {
                ptr=ptr->next;
                slow=slow->next;
            }
            return ptr;
        }
       } 
       return NULL;
    }
};