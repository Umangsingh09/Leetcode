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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
         if (head == NULL || left == right)
            return head;

        ListNode *prev = NULL;
        ListNode *curr = head;
        int pos = 1;

        while (pos < left) {
            prev = curr;
            curr = curr->next;
            pos++;
        }

        ListNode *before = prev;
        ListNode *last = curr;   

        while (pos <= right) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            pos++;
        }

        if (before != NULL)
            before->next = prev;
        else
            head = prev;

        last->next = curr;

        return head;
    }
};