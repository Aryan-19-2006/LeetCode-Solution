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
#include <numeric>

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *a = head;
        ListNode *temp = NULL;

        while (a != NULL && a->next != NULL) {
            temp = a->next;

            ListNode *node = new ListNode(std::gcd(a->val, temp->val));
            a->next = node;
            node->next = temp;

            a = temp;
        }

        return head;
    }
};