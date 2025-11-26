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
        // if(!head)
        // return head;

        int count = 0;

        ListNode* temp = head;

        while(temp){
            count++;
            temp = temp -> next;
        }

        k = k % count;

        if(k == 0)
        return head;

        count -= k; // reach at (count - k)th node for deleting pointer

        ListNode* prev = NULL, *curr = head;

        while(count--){
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = NULL;

        ListNode* tail = curr;

        while(tail -> next){
            tail = tail -> next;
        }

        tail -> next = head;

        return curr;
    }
};