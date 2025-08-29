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
        
        while(n--){
            temp = temp -> next;
        }

        if(!temp){
            ListNode* curr = head -> next;
            delete(head);
            return curr;
        }
        

        ListNode* prev = head;
        while(temp && temp -> next){
            prev = prev -> next;
            temp = temp -> next;
        }

        prev -> next = prev -> next -> next;

        return head;
    }
};