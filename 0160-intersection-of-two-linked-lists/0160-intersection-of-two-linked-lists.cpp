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
    ListNode* solve(ListNode* l1, ListNode* l2, int diff){
        for(int i = 0; i < diff; i++){
            l1 = l1 -> next;
        }

        while(l1 && l2){
            if(l1 == l2)
            return l1;

            l1 = l1 -> next;
            l2 = l2 -> next;
        }

        return NULL;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = 0, n2 = 0;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1){
            n1++;
            temp1 = temp1 -> next;
        }

        while(temp2){
            n2++;
            temp2 = temp2 -> next;
        }

        if(n1 > n2){
            return solve(headA, headB, n1 - n2);
        }
        else
        return solve(headB, headA, n2 - n1); // pass greater list as l1
    }
};