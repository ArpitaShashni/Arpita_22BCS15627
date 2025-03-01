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
 #include<queue>
class Solution {
public:
    class compare{
    public:
        bool operator()(ListNode* a,ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> minheap;
        int k=lists.size();
        if(k==0){
            return NULL;
        }
        for(int i=0;i<k;i++){
            if(lists[i]!=NULL){
                minheap.push(lists[i]);

            }
        }
        ListNode* head=NULL;
        ListNode* tail=NULL;
        while(minheap.size()>0){
            ListNode* temp=minheap.top();
            minheap.pop();
            if(head==NULL){
                head=temp;
                tail=temp;
                if(head->next!=NULL){
                    minheap.push(tail->next);
                }
            }
            else{
                tail->next=temp;
                tail=temp;
                if(tail->next!=NULL){
                    minheap.push(tail->next);
                }
            }
        }
        return head;
    }
};