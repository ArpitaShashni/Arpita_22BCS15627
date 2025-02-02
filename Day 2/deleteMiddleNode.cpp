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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL){
            return NULL;
        }
        ListNode* temp=head;
        int n=0;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        temp=head;
        int a=n/2;
        int x=0;
        while(temp!=NULL){
            x++;
            if(x==a){
                break;
            }
            temp=temp->next;
        }
        ListNode* c=temp->next;
        temp->next=c->next;
        delete c;
        return head;
    }
};