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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL){
        cout<<"LL is empty"<<endl;
        return NULL;
    }

    int len = 0;
    ListNode * temp = head;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    if(k > len){
        return head;
    }

    ListNode * prev = NULL;
    ListNode * curr = head;
    ListNode * right = curr -> next;
    int count = 0;

    while(count < k){
        right = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = right;
        count++;
    }

    // step 2: reverse call
    if(right != NULL){
        head->next = reverseKGroup(right,k);
    }

    return prev;
    }
};