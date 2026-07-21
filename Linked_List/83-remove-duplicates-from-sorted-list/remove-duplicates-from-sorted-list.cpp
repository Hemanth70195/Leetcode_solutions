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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
        {
            return nullptr;
        }
        ListNode * temp = head;
        while(temp->next)
        {
            if(temp->val != temp->next->val)
            {
                temp=temp->next;
            }
            else
            {
                temp->next= temp->next->next;            }
        }
        return head;
    }
};