/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry = 0;
    int num = 0;
    struct ListNode * curr1 = l1;
    struct ListNode * curr2 = l2;
    struct ListNode * ans = NULL;
    struct ListNode * currAns = ans;

    while (curr1 != NULL || curr2 != NULL || carry == 1) {
        num = carry;
        if (curr1 != NULL) {
            num += curr1->val;
            curr1 = curr1->next;
        }
        if (curr2 != NULL) {
            num += curr2->val;
            curr2 = curr2->next;
        }
        carry = num/10;
        
        struct ListNode * nextAns = malloc(sizeof(struct ListNode));
        nextAns->val = num%10;
        nextAns->next = NULL;
        if (ans == NULL) {
            ans = nextAns;
            currAns = ans;
        } else{
            currAns->next = nextAns;
            currAns = nextAns;
        }
    }

    return ans;
}
