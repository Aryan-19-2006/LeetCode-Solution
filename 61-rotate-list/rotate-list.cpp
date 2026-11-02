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
        ListNode* slow=head;
        ListNode* fast=head;
        int n = 1;
        ListNode* temp = head;
        if(head == NULL || head->next == NULL || k==0) return head;
        while (temp->next != NULL) {
            temp = temp->next;
            n++;
        }

        k = k % n;
       if(k==0)return head;
        for(int i=0;i<k;i++)
            fast=fast->next;
        while(fast->next != NULL){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* NewHead = slow->next;
        slow->next= NULL;
        fast->next=head;
        return NewHead;
    }
};