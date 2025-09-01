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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2, s3;

        while(l1){
            s1.push(l1 -> val);
            l1 = l1 -> next;
        }

        while(l2){
            s2.push(l2 -> val);
            l2 = l2 -> next;
        }

        int carry = 0;

        while(!s1.empty() || !s2.empty()){
            int sum = carry;

            if(!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                sum += s2.top();
                s2.pop();
            }

            s3.push(sum % 10);
            carry = sum / 10;
        }

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(!s3.empty()){
            temp -> next = new ListNode(s3.top());
            s3.pop();
            temp = temp -> next;
        }

        return dummyNode -> next;
    }
};