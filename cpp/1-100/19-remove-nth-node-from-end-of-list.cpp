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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * fast = head;
        ListNode * slow = head;
        for (int i = 0; i <= n; i++) {
            if (fast == NULL) {
                head = slow->next;
                delete slow;
                return head;
            }
            fast = fast->next;
        }
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = fast->next;
        delete fast;
        return head;
    }
};
