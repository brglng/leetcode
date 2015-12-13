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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* resultNode = result;
        int carry = 0;
        while (l1 || l2 || carry > 0) {
            resultNode->val = 0;
            if (l1) {
                resultNode->val += l1->val;
            }
            if (l2) {
                resultNode->val += l2->val;
            }
            if (carry) {
                resultNode->val += carry;
            }
            if (resultNode->val > 9) {
                resultNode->val -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            if ((l1 && l1->next) || (l2 &&  l2->next) || carry > 0) {
                resultNode->next = new ListNode(0);
            }
            resultNode = resultNode->next;
            
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        return result;
    }
};
