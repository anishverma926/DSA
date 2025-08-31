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
        ListNode* temp = head;

        int len = 0;
        while(temp){
            len++;
            temp = temp -> next;
        }

        // If n == len (remove the head) 
        if(n == len){
            ListNode* newHead = head -> next;
            delete(head);
            return newHead;
        }

        int startLen = len - n;
        temp = head;

        while(startLen-- > 1){  // if startLen-- then temp will the reach at 4
            temp = temp -> next;
        }

        ListNode* delNode = temp -> next;
        temp -> next = temp -> next -> next;
        delete(delNode);

        return head;
    }
};