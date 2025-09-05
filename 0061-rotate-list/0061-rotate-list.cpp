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
        if(!head)
        return head;

        ListNode* temp = head;
        int len = 0;

        while(temp){
            len++;
            temp = temp -> next;
        }

        k = k % len;
        len -= k;

        if(k % len == 0)
        return head;


        ListNode* curr = head;
        ListNode* prev = NULL;

        while(len--){
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = NULL;
        ListNode* tail = curr;

        while(tail -> next){
            tail = tail -> next;
        }
        tail -> next = head;
        head = curr;

        return head;
    }
};