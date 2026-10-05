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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* nextnode;

        // Reach node at position a - 1
        for (int i = 0; i < a - 1; i++) {
            temp1 = temp1->next;
        }

        // Find node after position b
        nextnode = temp1;
        for (int i = a - 1; i <= b; i++) {
            nextnode = nextnode->next;
        }

        // Connect list1 to list2
        temp1->next = list2;

        // Go to end of list2
        ListNode* temp2 = list2;
        while (temp2->next) {
            temp2 = temp2->next;
        }

        // Connect list2 to remaining list1
        temp2->next = nextnode;

        return list1;
    }
};
