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
        ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        // Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode* reverseHead = reverse(slow);

        // Compare the two halves
        ListNode* temp1 = head;
        ListNode* temp2 = reverseHead;

        bool isPalin = true;
        while (temp2 != NULL) {
            if (temp1->val != temp2->val) {
                isPalin = false;
                break;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        // Restore the list (optional)
        reverse(reverseHead);

        return isPalin;
    }
};