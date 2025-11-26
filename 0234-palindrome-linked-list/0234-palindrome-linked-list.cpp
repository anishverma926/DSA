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
    bool isPalindrome(ListNode* head) {

        if(!head || !head -> next)
        return true;
        
        int count = 0;

        ListNode* temp = head;

        while(temp){
            count++;
            temp = temp -> next;
        }

        count /= 2;

        ListNode* prev = NULL, *curr = head;

        while(count--){
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = NULL;

        ListNode* front = NULL;
        prev = NULL;

        // reverse the LL

        while(curr){
            front = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = front;
        }

        // check both LL are equal or not

        ListNode* t1 = head, *t2 = prev;
        while(t1){
            if(t1 -> val != t2 -> val)
            return false;

            t1 = t1 -> next;
            t2 = t2 -> next;
        }

        return true;
    }
};