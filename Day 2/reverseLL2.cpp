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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *revs = NULL, *revs_prev = NULL;
        ListNode *revend = NULL, *revend_next = NULL;
        int i = 1;
        ListNode* curr = head;
        while (curr && i <= right) {
            if (i < left)
                revs_prev = curr;
            if (i == left)
                revs = curr;
            if (i == right) {
                revend = curr;
                revend_next = curr->next;
            }
            curr = curr->next;
            i++;
        }
        revend->next = NULL;
        revend = reverse(revs);
        if (revs_prev)
            revs_prev->next = revend;
        else
            head = revend;
        revs->next = revend_next;
        return head;
    }
};