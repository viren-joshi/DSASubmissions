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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *current = head, *nextNode, *newNode;
        while(current != NULL) {
            nextNode = current->next;
            if(nextNode == NULL) break;
            newNode = new ListNode(calcGCD(current->val, nextNode->val));
            current->next = newNode;
            newNode->next = nextNode;
            current = nextNode;
        }
        return head;
    }

    int calcGCD(int a,int b) {
        int temp;
        while(b!=0) {
            temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }
};