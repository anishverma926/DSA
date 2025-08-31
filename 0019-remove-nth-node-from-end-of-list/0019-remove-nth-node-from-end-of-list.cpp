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
    int getLength(ListNode* head){
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        } 
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;

        int len = getLength(head);
        if(len == n){
            temp = head->next;
            delete(head);
            return temp;
        }

        int travelLen = len - n;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(travelLen --){
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;
        delete(curr);

        return head;
    }
};