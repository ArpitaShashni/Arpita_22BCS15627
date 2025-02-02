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
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }
        ListNode* temp = head;
        int len = 0;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }
        k = k % len;
        if (k == 0) {
            return head; 
        }
        ListNode* tail = head;
        for (int i = 1; i < len - k; i++) {
            tail = tail->next;
        }
        ListNode* newHead = tail->next; 
        tail->next = NULL;            
        temp = newHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head;

        return newHead;
    }
};