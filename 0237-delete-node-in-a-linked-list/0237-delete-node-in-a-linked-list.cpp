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
    // Step 1: Copy the next node’s value into node
    // Step 2: Skip the next node
    // Step 3: Delete the skipped node (to free memory)

    void deleteNode(ListNode* node) {
        node -> val = node -> next -> val;  // replace 1 to 9

        ListNode* temp = node -> next;  // temp at 1 
        node -> next = node -> next -> next; // connect 9 to next node

        delete(temp); 
    }
};