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
    ListNode* middleNode(ListNode* head) {
        int size = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            size++;
            temp = temp->next;
        }
        int mid = size%2==0 ? size/2 + 1 : ceil(size/2.0);
        temp = head;
        while(mid > 1) {
            temp = temp->next;
            mid--;
        }
        return temp;
    }
};
